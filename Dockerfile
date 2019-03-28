FROM gcc:7.3.0

RUN apt-get -qq update
RUN apt-get -qq upgrade
RUN apt-get -qq install cmake

RUN apt-get -qq install libboost-all-dev=1.62.0.1
RUN apt-get -qq install build-essential libtcmalloc-minimal4 libssl-dev && \
  ln -s /usr/lib/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

RUN apt install -y libmysqlcppconn-dev

WORKDIR /usr/src/app
COPY app/* /usr/src/app/

#WORKDIR /usr/src/app/build
#RUN cmake .
#RUN make
#CMD ["./main"]

EXPOSE 8084