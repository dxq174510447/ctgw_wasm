
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

