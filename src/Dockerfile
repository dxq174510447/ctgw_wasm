FROM docker.io/istio/proxyv2:1.8.1

COPY ./ctgw.wasm /home/istio-proxy/ctgw.wasm

RUN chown istio-proxy:istio-proxy /home/istio-proxy/ctgw.wasm \
   && chmod 777 /home/istio-proxy/ctgw.wasm \
   && mkdir -p /var/lib/istio/data \
   && chown istio-proxy:istio-proxy /var/lib/istio/data \
   && echo "asd" >> /var/lib/istio/data/out.log \
   && chown istio-proxy:istio-proxy /var/lib/istio/data/out.log \
   && chmod 666 /var/lib/istio/data/out.log
