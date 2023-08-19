#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll mod = 1000000007;

// Modulo multiplicative inverse
template < typename T = int > struct Modulo_multiplicative_inverse{
 
  Modulo_multiplicative_inverse() = default;
 
  T n, r, Mod;
  vector < T > fact, inv_fact;
 
  auto Take_mod(T a, T b) -> ll {
     return (a % mod * b % mod) % mod;
  };
 
  Modulo_multiplicative_inverse(T n, T Mod) : n(n), Mod(Mod) {
    fact = vector < T > (n + 1, 1);
    inv_fact = vector < T > (n + 1, 1);
    for (T i = 1; i <= n; i++) fact[i] = Take_mod(fact[i - 1], i);
    inv_fact[n] = Modulo_Inverse(fact[n]);
    for (T i = n - 1; i >= 0; i--) inv_fact[i] = Take_mod(inv_fact[i + 1], i + 1);
  }
 
  T fast_power(T a, T b){
    T res = 1;
    while (b){
      if (b & 1) res = Take_mod(res, a);
      a = Take_mod(a, a);
      b >>= 1;
    }
    return res;
  }
  
  // fact[n] / (fact[r] * fact[n - r]) = fact[n] * (fact[r] * fact[n - r])^-1 = fact[n] * inv_fact[r] * inv_fact[n - r]
  T nCr(T n, T r){
    if (n < r) return 0;
    return Take_mod(fact[n], Take_mod(inv_fact[r], inv_fact[n - r]));
  }
 
  // fact[n] / fact[n - r] = fact[n] * (fact[n - r])^-1 = fact[n] * inv_fact[n - r] 
  T nPr(T n, T r){
    if (n < r) return 0;
    return Take_mod(fact[n], inv_fact[n - r]);
  }
 
  T Modulo_Inverse(T a){
    return fast_power(a, Mod - 2);
  }
 
};

int main()
{


  ll n, r;
  cin >> n >> r;

  Modulo_multiplicative_inverse < ll > P(n, mod);

  cout << P.nCr(n, r) << "\n";
  cout << P.nPr(n, r) << "\n";

  ll a, b, c;
  cin >> a >> b >> c;

  // (a / b) % c = (a % c * b^-1 % c) % c
  // b^-1 = modulo multiplicative inverse of b

  b = P.Modulo_Inverse(b);  
  cout << (a % mod * b % mod) % c << "\n";


  return 0;
}
