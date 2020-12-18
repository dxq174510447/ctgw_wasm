// NOLINT(namespace-envoy)
#include <string>
#include <string_view>
#include <unordered_map>
#include <fstream>

#include "proxy_wasm_intrinsics.h"


class ExampleRootContext : public RootContext {
private:
	std::ofstream outputfile;
public:
  explicit ExampleRootContext(uint32_t id, std::string_view root_id) : RootContext(id, root_id) {
	  outputfile = outputfile.open("/var/lib/istio/data/out.log");
  }

  bool onStart(size_t) override;
  bool onConfigure(size_t) override;
  void onTick() override;
  std::ofstream getLog();
};

class ExampleContext : public Context {
private:
	ExampleRootContext* root;
public:
  explicit ExampleContext(uint32_t id, RootContext* root) : Context(id, root) {
	  this->root = (ExampleRootContext *)root;
  }

  void onCreate() override;
  FilterHeadersStatus onRequestHeaders(uint32_t headers, bool end_of_stream) override;
  FilterDataStatus onRequestBody(size_t body_buffer_length, bool end_of_stream) override;
  FilterHeadersStatus onResponseHeaders(uint32_t headers, bool end_of_stream) override;
  FilterDataStatus onResponseBody(size_t body_buffer_length, bool end_of_stream) override;
  void onDone() override;
  void onLog() override;
  void onDelete() override;
  std::ofstream getLog();
};
static RegisterContextFactory register_ExampleContext(CONTEXT_FACTORY(ExampleContext),
                                                      ROOT_FACTORY(ExampleRootContext),
                                                      "my_root_id");

std::ofstream ExampleRootContext::getLog(){
	return this->outputfile;
}

bool ExampleRootContext::onStart(size_t) {
  LOG_TRACE("onStart");
 // outputfile << "onStart log---" << std::endl ;
 // rt.outputfile << "onStart log---" << std::endl ;
  return true;
}

bool ExampleRootContext::onConfigure(size_t) {
//  outputfile.open("/var/lib/istio/data/out.log");
  LOG_TRACE("onConfigure");
  this->getLog() << "onConfigure log---" << std::endl ;
  proxy_set_tick_period_milliseconds(1000); // 1 sec
  return true;
}

void ExampleRootContext::onTick() { LOG_TRACE("onTick"); }

std::ofstream ExampleContext::getLog(){
	return this->root->getLog();
}

void ExampleContext::onCreate() { LOG_WARN(std::string("onCreate " + std::to_string(id()))); }

FilterHeadersStatus ExampleContext::onRequestHeaders(uint32_t, bool) {
  LOG_DEBUG(std::string("onRequestHeaders ") + std::to_string(id()));
  auto result = getRequestHeaderPairs();
  auto pairs = result->pairs();
  LOG_INFO(std::string("headers: ") + std::to_string(pairs.size()));
  for (auto& p : pairs) {
    LOG_INFO(std::string(p.first) + std::string(" -> ") + std::string(p.second));
  }
  return FilterHeadersStatus::Continue;
}

FilterHeadersStatus ExampleContext::onResponseHeaders(uint32_t, bool) {
  LOG_DEBUG(std::string("onResponseHeaders ") + std::to_string(id()));
  auto result = getResponseHeaderPairs();
  auto pairs = result->pairs();
  LOG_INFO(std::string("headers: ") + std::to_string(pairs.size()));
  for (auto& p : pairs) {
    LOG_INFO(std::string(p.first) + std::string(" -> ") + std::string(p.second));
  }
  addResponseHeader("newheader", "newheadervalue");
  replaceResponseHeader("location", "envoy-wasm");
  return FilterHeadersStatus::Continue;
}

FilterDataStatus ExampleContext::onRequestBody(size_t body_buffer_length,
                                               bool /* end_of_stream */) {
  auto body = getBufferBytes(WasmBufferType::HttpRequestBody, 0, body_buffer_length);
  LOG_ERROR(std::string("onRequestBody ") + std::string(body->view()));
  return FilterDataStatus::Continue;
}

FilterDataStatus ExampleContext::onResponseBody(size_t /* body_buffer_length */,
                                                bool /* end_of_stream */) {
  setBuffer(WasmBufferType::HttpResponseBody, 0, 3, "foo");
  return FilterDataStatus::Continue;
}

void ExampleContext::onDone() { LOG_WARN(std::string("onDone " + std::to_string(id()))); }

void ExampleContext::onLog() { LOG_WARN(std::string("onLog " + std::to_string(id()))); }

void ExampleContext::onDelete() { LOG_WARN(std::string("onDelete " + std::to_string(id()))); }
