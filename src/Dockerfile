FROM docker.io/istio/proxyv2:1.8.1

COPY ./ctgw.wasm /home/istio-proxy/ctgw.wasm

RUN chown istio-proxy:istio-proxy /home/istio-proxy/ctgw.wasm \
   && chmod 777 /home/istio-proxy/ctgw.wasm

