FROM gcc:latest

WORKDIR /app

COPY Canonical.cpp BruteForce.cpp SHP.cpp main.cpp header.hpp ./

RUN g++ -O2 -std=c++17 -o lab2 Canonical.cpp BruteForce.cpp SHP.cpp main.cpp

ENTRYPOINT ["./lab2"]
