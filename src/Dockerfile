FROM docker.io/istio/proxyv2:1.8.1


COPY ./ctgw.wasm /lib/ctgw.wasm

RUN mkdir -p /var/log/envoy \
   && chown istio-proxy:istio-proxy /var/log/envoy \
   && chmod 777 /var/log/envoy
   
COPY ./ctgw.wasm /var/log/envoy/ctgw.wasm

RUN chown istio-proxy:istio-proxy /var/log/envoy/ctgw.wasm \
   && chmod 777 /var/log/envoy/ctgw.wasm

