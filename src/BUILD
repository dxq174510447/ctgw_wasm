
load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_package",
)
load("@envoy//bazel/wasm:wasm.bzl", "envoy_wasm_cc_binary")

envoy_package()

envoy_wasm_cc_binary(
    name = "envoy_filter_http_wasm_example.wasm",
    srcs = ["ctgw.cpp"],
    deps = [
        "@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
    ],
)

cc_binary(
    name = "wasm",
    srcs = ["seclang.cpp"],
    deps = [
    	"@hiredis_libsr//:hiredis_libs",
    	"@hiredis_headersr//:hiredis_headers",
    	"@redisplus_libsr//:redisplus_libs",
    	"@redisplus_headersr//:redisplus_headers",
    	":t1"
    ],
    linkopts = [
    	"-lm",
    	"-std=c++17",
    	"-stdlib=libc++",
    	"-pthread"
    ],
    copts = [
    	"-std=c++17",
    	"-stdlib=libc++",
    	"-pthread"
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "t1",
    srcs = ["ttt/t1.cpp"],
    hdrs = ["ttt/t1.h"]
)

