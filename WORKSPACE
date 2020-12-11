
# load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



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


# 1. Determine SHA256 `wget https://github.com/envoyproxy/envoy/archive/$COMMIT.tar.gz && sha256sum $COMMIT.tar.gz`
# 2. Update .bazelversion, envoy.bazelrc and .bazelrc if needed.
#
# Note: this is needed by release builder to resolve envoy dep sha to tag.
# Commit date: 2020-11-20
ENVOY_SHA = "31e225b628a316322a0bcbd237a143eade995d22"

ENVOY_SHA256 = "079516e413c07e2ca19374c9baa1cafe7c6ee1b160e74c6427b9fee0709fa953"

ENVOY_ORG = "envoyproxy"

ENVOY_REPO = "envoy"

# To override with local envoy, just pass `--override_repository=envoy=/PATH/TO/ENVOY` to Bazel or
# persist the option in `user.bazelrc`.
http_archive(
    name = "envoy",
    sha256 = ENVOY_SHA256,
    strip_prefix = ENVOY_REPO + "-" + ENVOY_SHA,
    url = "https://github.com/" + ENVOY_ORG + "/" + ENVOY_REPO + "/archive/" + ENVOY_SHA + ".tar.gz",
)

