FROM ubuntu:22.04
COPY  . /app
WORKDIR /app
RUN apt-get update
RUN apt-get install -y make gcc libncurses-dev splint
#RUN gcc main.c visualiser.c langton.c -lncursesw -o ant
#alt to make file
