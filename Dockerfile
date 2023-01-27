FROM ubuntu:22.04
COPY  . /app
WORKDIR /app
RUN apt update
RUN apt-get install -y make gcc libncurses-dev gdb
RUN gcc main.c visualiser.c langton.c -lncurses -o ant

# gcc -Wall -Wstrict-prototypes -Wmissing-prototypes -Wshadow