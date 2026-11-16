#pragma once

#include <iostream>
#include <cstdint>

template <int MOD>
struct ModInt {
  int val;

  constexpr ModInt() : val(0) {}
  constexpr ModInt(long long v) {
    v %= MOD;
    if (v < 0) v += MOD;
    val = static_cast<int>(v);
  }

  static constexpr int mod() { return MOD; }

  ModInt power(long long p) const {
    ModInt res = 1, base = *this;
    while (p > 0) {
      if (p & 1) res *= base;
      base *= base;
      p >>= 1;
    }
    return res;
  }

  ModInt inv() const {
    return power(MOD - 2);
  }

  ModInt& operator+=(const ModInt& other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  ModInt& operator-=(const ModInt& other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }

  ModInt& operator*=(const ModInt& other) {
    val = static_cast<int>(1LL * val * other.val % MOD);
    return *this;
  }

  ModInt& operator/=(const ModInt& other) {
    return *this *= other.inv();
  }

  friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

  friend bool operator==(const ModInt& a, const ModInt& b) { return a.val == b.val; }
  friend bool operator!=(const ModInt& a, const ModInt& b) { return a.val != b.val; }

  friend std::ostream& operator<<(std::ostream& os, const ModInt& m) { return os << m.val; }
  friend std::istream& operator>>(std::istream& is, ModInt& m) {
    long long v;
    is >> v;
    m = ModInt(v);
    return is;
  }
};

using Mint = ModInt<1'000'000'007>;
using Mint998 = ModInt<998'244'353>;
