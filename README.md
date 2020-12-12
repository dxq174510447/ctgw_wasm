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

2.	下载项目，通过编译命令生成wasm文件

```sh
docker run -v $PWD:/work -w /work  wasmsdk:v2 /build_wasm.sh
```

3.	部署代码机器kubectl命令，让其可直接连接k8s环境


4. 将wasm文件放到configmap中

```sh
kubectl create configmap ct-wasm --from-file=myproject.wasm --namespace=istio-system
```

5. 将