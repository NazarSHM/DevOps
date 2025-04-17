FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y g++ curl && apt-get clean

WORKDIR /app

COPY main.cpp .
COPY FuncA.cpp .
COPY FuncA.h .
COPY httplib.h .

RUN g++ main.cpp FuncA.cpp -o http_server -lpthread


EXPOSE 80
CMD ["./http_server"]
