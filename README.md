## 编译


```sh
clang toolchain with libc++ configured
bazel release build...
Building...
 bazel build --config=libc++ --verbose_failures --show_task_finish --experimental_generate_json_trace_profile --test_output=errors --repository_cache=/build/repository_cache --experimental_repository_cache_hardlinks --nocache_test_results -c opt //source/exe:envoy-static
```