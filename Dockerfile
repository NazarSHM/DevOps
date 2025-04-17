# Stage 1: Build the application
FROM debian:bullseye AS builder

RUN apt update && apt install -y g++ make automake autoconf libtool git

RUN git clone --branch branchHTTPserver https://github.com/NazarSHM/DevOps.git /app
WORKDIR /app

RUN chmod +x autogen.sh && ./autogen.sh && make

# Stage 2: Use slim Debian to avoid musl/glibc issues
FROM debian:bullseye-slim

# Встановлюємо лише runtime-бібліотеки C++
RUN apt update && apt install -y libstdc++6

# Копіюємо зібраний виконуваний файл
COPY --from=builder /app/http_server /http_server

EXPOSE 8080

CMD ["/http_server"]
