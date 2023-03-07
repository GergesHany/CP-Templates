#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
const ll mod = 1000000007;


// Modulo multiplicative inverse
template < typename T = int > struct Modulo_multiplicative_inverse{

  Modulo_multiplicative_inverse() = default;

  T n, r, Mod;
  vector < T > fact, inv_fact;

  Modulo_multiplicative_inverse(T n, T r, T Mod) : n(n), r(r), Mod(Mod) {
    fact = vector < T > (n + 1, 1);
    inv_fact = vector < T > (n + 1, 1);
    for (T i = 1; i <= n; i++) {
      fact[i] = (fact[i - 1] * i) % Mod;
      inv_fact[i] = Modulo_Inverse(fact[i]);
    }
  }

  T fast_power(T a, T b){
    T res = 1;
    while (b){
      if (b & 1) res = (res % Mod * a % Mod) % Mod;
      a = (a % Mod * a % Mod) % Mod;
      b >>= 1;
    }
    return res;
  }
  
  // fact[n] / (fact[r] * fact[n - r]) = fact[n] * (fact[r] * fact[n - r])^-1 = fact[n] * inv_fact[r] * inv_fact[n - r]
  T nCr(T n, T r){
    if (n < r) return 0;
    return (fact[n] * inv_fact[r] % Mod * inv_fact[n - r] % Mod) % Mod;
  }

  // fact[n] / fact[n - r] = fact[n] * (fact[n - r])^-1 = fact[n] * inv_fact[n - r] 
  T nPr(T n, T r){
    if (n < r) return 0;
    return (fact[n] * inv_fact[n - r] % Mod) % Mod;
  }

  T Modulo_Inverse(T a){
    return fast_power(a, Mod - 2);
  }

};


int main()
{
  

  ll n, r;
  cin >> n >> r;

  Modulo_multiplicative_inverse < ll > P;
  P = Modulo_multiplicative_inverse < ll > (n, r, mod);

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
