FROM ubuntu
LABEL org.opencontainers.image.source https://github.com/fegrue/OSMP

RUN mkdir /osmp


WORKDIR /osmp
COPY . .
RUN apt update && apt install cmake gcc -y
RUN mkdir build
RUN cmake -B build -S . && cmake --build build
ENTRYPOINT [ "./testall.sh"]