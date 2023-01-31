FROM ubuntu:22.04
COPY  . /app
WORKDIR /app
RUN apt-get update
RUN apt-get install -y make gcc libncurses-dev cpplint