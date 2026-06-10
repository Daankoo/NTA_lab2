#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <chrono>

using namespace chrono;
using namespace std;

// Operations.cpp
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t n);
uint64_t mod_step(uint64_t a, uint64_t b, uint64_t n);

// MillerRabin.cpp
void     step2(uint64_t p, uint64_t& d, uint64_t& s);
bool     TestSPP(uint64_t p, uint64_t a, uint64_t d, uint64_t s);
bool     MillerRabin(uint64_t p, int k);

// Pollard.cpp
uint64_t TrialDivision(uint64_t n);
uint64_t PollardRho(uint64_t n);