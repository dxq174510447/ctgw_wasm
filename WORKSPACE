
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")



http_archive(
    name = "redis",
    strip_prefix = "cpp_redis-master",
    url = "https://github.com/cpp-redis/cpp_redis/archive/master.zip",
)

load("@redis//:repositories.bzl", "cpp_redis_repositories")

cpp_redis_repositories()
