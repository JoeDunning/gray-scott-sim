FROM debian:latest AS build

RUN apt-get update && apt-get install -y cmake

WORKDIR /app

COPY . /app


RUN cmake -S . -B /app/build

RUN cmake --build /app/build

FROM debian:latest

WORKDIR /app

COPY --from=build /app/build/main_target /app
COPY --from=build /app/build/test_exec /app

CMD  ["./main_target"]