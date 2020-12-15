## 编译


```sh
clang toolchain with libc++ configured
bazel release build...
Building...
 bazel build --config=libc++ --verbose_failures --show_task_finish --experimental_generate_json_trace_profile --test_output=errors --repository_cache=/build/repository_cache --experimental_repository_cache_hardlinks --nocache_test_results -c opt //source/exe:envoy-static
```


## 构建

1.	先下载接口项目 https://github.com/proxy-wasm/proxy-wasm-cpp-sdk ，生成构建镜像 

```sh
docker build -t wasmsdk:v2 -f Dockerfile-sdk .
```

2.	部署代码机器kubectl命令，让其可直接连接k8s环境


3.	下载项目，通过编译命令生成wasm文件

```sh
docker run -v $PWD:/work -w /work  wasmsdk:v2 /build_wasm.sh
```




4. 构建包含wasm文件的envoy镜像

```sh
docker build -t cproxyv2:1.7.4  .
docker tag cproxyv2:1.7.4 registry.dev.chelizitech.com/saas/cproxyv2:1.7.4
docker push registry.dev.chelizitech.com/saas/cproxyv2:1.7.4
```

5. 修改istio default的镜像默认值  
/root/istio/istio-1.7.4/manifests/profiles/default.yaml的.Values.global.proxy.image改成registry.dev.chelizitech.com/saas/cproxyv2:1.7.4，顺便把日志级别改成info

位于istioctl install --manifests ~/istio/istio-1.7.4/manifests,

6. 安装

```sh

kubectl apply -f - <<EOF
apiVersion: networking.istio.io/v1alpha3
kind: EnvoyFilter
metadata:
  name: ctgw-filter1
  namespace: istio-system
spec:
  configPatches:
  - applyTo: HTTP_FILTER
    match:
      context: GATEWAY
      listener:
        filterChain:
          filter:
            name: envoy.filters.network.http_connection_manager
            subFilter:
              name: envoy.filters.http.router
    patch:
      operation: INSERT_BEFORE
      value:
        name: envoy.filters.http.wasm
        typed_config:
          '@type': type.googleapis.com/udpa.type.v1.TypedStruct
          type_url: type.googleapis.com/envoy.extensions.filters.http.wasm.v3.Wasm
          value:
            config:
              name: ctgw_plugin
              configuration: 
                "@type": "type.googleapis.com/google.protobuf.StringValue"
                value: |
                  {}
              vm_config:
                runtime: envoy.wasm.runtime.v8
                code:
                  local:
                    filename: lib/ctgw.wasm
EOF

```


```
istioctl proxy-config listener istio-ingressgateway-89dcb5fd6-sn44n  -n=istio-system --port 8080 --type HTTP -o json
```