#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <chrono>
#include <map>

using namespace chrono;
using namespace std;

// Operations
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t n);
uint64_t mod_step(uint64_t a, uint64_t b, uint64_t n);

// MillerRabin
void     step2(uint64_t p, uint64_t& d, uint64_t& s);
bool     TestSPP(uint64_t p, uint64_t a, uint64_t d, uint64_t s);
bool     MillerRabin(uint64_t p, int k);

// Pollard
uint64_t TrialDivision(uint64_t n);
uint64_t PollardRho(uint64_t n);

// Canonical
void Factorize(uint64_t n, vector<uint64_t>& result);
map<uint64_t, int> canonical_decomposition(uint64_t n);
