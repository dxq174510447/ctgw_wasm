
#load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



# http_archive(
#    name = "redis",
#    strip_prefix = "cpp_redis-master",
#    url = "https://github.com/cpp-redis/cpp_redis/archive/master.zip",
#)

# load("@redis//:repositories.bzl", "cpp_redis_repositories")

# cpp_redis_repositories()

new_local_repository(
    name = "hiredis_libsr",
    path = "/usr/local/hiredis/lib",
    build_file_content = """
cc_library(
    name = "hiredis_libs",
    srcs = ["libhiredis.a"],
    visibility = ["//visibility:public"]
)
"""
)

new_local_repository(
    name = "hiredis_headersr",
    path = "/usr/local/hiredis/include",
    build_file_content = """
cc_library(
    name = "hiredis_headers",
    hdrs = glob([
        "hiredis/*.h", "hiredis/*.hpp"
    ]),
    visibility = ["//visibility:public"]
)
"""
)


new_local_repository(
    name = "redisplus_libsr",
    path = "/usr/local/redis-plus-plus/lib",
    build_file_content = """
cc_library(
    name = "redisplus_libs",
    srcs = ["libredis++.a"],
    visibility = ["//visibility:public"]
)
"""
)

new_local_repository(
    name = "redisplus_headersr",
    path = "/usr/local/redis-plus-plus/include",
    build_file_content = """
cc_library(
    name = "redisplus_headers",
    hdrs = glob([
        "sw/redis++/*.h", "sw/redis++/*.hpp",
    ]),
    visibility = ["//visibility:public"]
)
"""
)

#http_archive(
#    name = "envoy",
#    strip_prefix = "envoy-31e225b628a316322a0bcbd237a143eade995d22",
#    url = "https://wx.dev.chelizitech.com/files/envoy-31e225b628a316322a0bcbd237a143eade995d22.tar.gz",
#)


#http_archive(
#    name = "proxy_wasm_cpp_sdk",
#    strip_prefix = "proxy-wasm-cpp-sdk-b5ff880ed13d93dde9faf53d0aa05b216cc60b86",
#    url = "https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/archive/b5ff880ed13d93dde9faf53d0aa05b216cc60b86.tar.gz",
#)


