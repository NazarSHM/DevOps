FROM debian:bullseye

RUN apt update && apt install -y g++ make automake autoconf libtool

COPY . /app
WORKDIR /app

RUN ./autogen.sh && ./configure && make

EXPOSE 8080
CMD ["./http_server"]
