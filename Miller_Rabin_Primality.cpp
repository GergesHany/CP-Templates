#include <bits/stdc++.h>
using namespace std;
#define ll long long

template < typename T = long long > struct Miller_Rabin_Primality{

  int rounds = 20;

  T binpow(T a, T b, T mod) {
    T res = 1;
    while (b > 0) {
      if (b & 1) res = binmul(res, a, mod);
      a = binmul(a, a, mod);
      b >>= 1;
    }
    return res;
  }

  T binmul(T a, T b, T mod) {
    T res = 0;
    while (b > 0) {
      if (b & 1) res = (res + a) % mod;
      a = (a + a) % mod;
      b >>= 1;
    }
    return res;
  }

  bool is_composite(T n, T a, T d, T s) { 
    T x = binpow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
      x = binmul(x, x, n);
      if (x == n - 1) return false;
    }
    return true;
  }

  bool is_prime(T n) {
    if (n < 4) return n == 2 || n == 3;
    if (n % 2 == 0 && n > 2) return false;    
    int r = 0;
    T d = n - 1;
    while ((d & 1) == 0) { 
      d >>= 1;
      r++;
    }
    for (int i = 0; i < rounds; i++) {
      T a = 2 + rand() % (n - 3); // find a random number in [2..n-2]
      if (is_composite(n, a, d, r)) return false;
    }
    return true;
  }

};


int main() {
  
  int x = 10;
  Miller_Rabin_Primality < ll > miller_rabin;
  cout << (miller_rabin.is_prime(x) ? "YES" : "NO") << endl;

  return 0;
}
