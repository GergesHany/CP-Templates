#include <bits/stdc++.h>
 
using namespace std; 
#define PI acos(-1)
#define sz(s) (int)(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define ceill(x, y)  ((x + y - 1) / y)
#define all(vec)  vec.begin(), vec.end()
#define Time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
 
int tt, tc;
typedef long long ll;
typedef long double ld;
const ll INF = 1LL << 60;
const int mod = 1e9 + 7, N = 1e6 + 5;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}


template < typename T = long long > struct Miller_Rabin_Primality{
 
  int rounds = 5; // The number of rounds of Miller-Rabin test to run
 
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
 
template < typename T = int > struct Linear_Sieve{
 
  vector < T > lp, pr;
  Linear_Sieve() = default;  
 
  Linear_Sieve(T N){
    lp = vector < T > (N + 1, 0);
    for (T i = 2; i <= N; ++i){
      if (!lp[i]) lp[i] = i, pr.push_back(i);
      for (T j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
      }
    }
  }
 
};
 
vector < ll > primes;
Linear_Sieve < ll > sieve(N);

template < typename T = long long > T num_of_divisors(T n) {
  T res = 1;
  for (auto &p : primes) {
    if (p * p * p > n) break;
    T cnt = 1;
    while (n % p == 0) n /= p, cnt++;
    res *= cnt;
  }
  ll sq = sqrt(n);
  Miller_Rabin_Primality < ll > MR;
  if (MR.is_prime(n)) res *= 2;
  else if (sq * sq == n && MR.is_prime(sq)) res *= 3;
  else if (n != 1) res *= 4;
  return res;
}
 
 
void Accepted(){

  
} 

int main(){ 

  primes = sieve.pr; // set the primes 
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
  }

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
