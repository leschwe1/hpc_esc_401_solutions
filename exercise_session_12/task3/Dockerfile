FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y build-essential g++ make python3 python3-pip && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY poisson_solver_serial /app

RUN make

CMD ["./main"]
