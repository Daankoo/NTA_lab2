#pragma once

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include <chrono>
#include <map>

using namespace std;
using namespace chrono;

// Operations
uint64_t gcd          (uint64_t a, uint64_t b);
int64_t  gcd_uv       (int64_t a, int64_t b, int64_t& u, int64_t& v);
uint64_t mod_inverse  (uint64_t a, uint64_t n);
uint64_t mul_mod      (uint64_t a, uint64_t b, uint64_t n);
uint64_t mod_step     (uint64_t a, uint64_t b, uint64_t n);

// MillerRabin
void     step2       (uint64_t p, uint64_t& d, uint64_t& s);
bool     TestSPP     (uint64_t p, uint64_t a, uint64_t d, uint64_t s);
bool     MillerRabin (uint64_t p, int k);

// Pollard
uint64_t TrialDivision (uint64_t n);
uint64_t PollardRho    (uint64_t n);

// Canonical
void Factorize(uint64_t n, vector<uint64_t>& result);
map<uint64_t, int> canonical_decomposition(uint64_t n);

// BruteForce.cpp
int64_t brute_force (uint64_t a, uint64_t b, uint64_t p);

// SHP.cpp
uint64_t crt             (vector<pair<uint64_t, uint64_t>>& congruences, uint64_t n);
uint64_t solve_for_prime (uint64_t a, uint64_t b, uint64_t p, uint64_t n, uint64_t prime, int exp);
uint64_t sph             (uint64_t a, uint64_t b, uint64_t p);