#pragma once

#include <vector>

// Linear Sieve computing minimum prime factors (spf) and primes in O(N)
struct Sieve {
  int n;
  std::vector<int> spf;
  std::vector<int> primes;

  explicit Sieve(int n_) : n(n_), spf(n_ + 1) {
    for (int i = 2; i <= n; i++) {
      if (spf[i] == 0) {
        spf[i] = i;
        primes.push_back(i);
      }
      for (int p : primes) {
        if (p > spf[i] || 1LL * i * p > n) break;
        spf[i * p] = p;
      }
    }
  }

  bool is_prime(int x) const {
    return x >= 2 && spf[x] == x;
  }

  // Prime factorization of x in O(log x)
  std::vector<std::pair<int, int>> factorize(int x) const {
    std::vector<std::pair<int, int>> factors;
    while (x > 1) {
      int p = spf[x];
      int count = 0;
      while (x % p == 0) {
        count++;
        x /= p;
      }
      factors.emplace_back(p, count);
    }
    return factors;
  }
};
