FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libosmium2-dev libprotozero-dev rapidjson-dev libboost-program-options-dev libbz2-dev libz-dev libexpat1-dev 

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install

FROM ubuntu:22.04 as package
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libboost-program-options-dev libexpat1-dev 
COPY --from=builder /install /install
