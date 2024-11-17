#include <bits/stdc++.h>
 
using namespace std; 
#define PI acos(-1)
// #define int long long
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

ll fact[N], inv[N];
ll mul(ll a, ll b);
ll binexp(ll n, ll k);
 
void init_fact() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < N; i++) fact[i] = mul(i, fact[i - 1]);
  inv[N - 1] = binexp(fact[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) inv[i] = mul(inv[i + 1], i + 1);
}
 
ll add(ll a, ll b) { return (a + b) % mod; }
ll sub(ll a, ll b) { return (a - b + mod) % mod; }
ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll divide(ll a, ll b) { return mul(a, binexp(b, mod - 2)); }

static bool calculate = []() { init_fact(); return true; }(); // call init_fact() when the program starts
 
ll binexp(ll n, ll k) {
  return k <= 0 ? 1 : mul(binexp(mul(n, n), k >> 1), k & 1 ? n : 1);
}
 
template < typename T = int > bool is_valid(T n, T r) {
  return n >= 0 && r >= 0 && n >= r;
}
 
// n! / (n - r)! 
// n * (n - 1) * (n - 2) * ... * (n - r + 1) 
ll permute(ll n, ll r) {
  return is_valid(n, r) ? mul(fact[n], inv[n - r]) : 0LL;
}
 
// n! / r!*(n - r)! 
// n * (n - 1) * (n - 2) * ... * 1 / r!
// nCr: r > (n - r) -> nCr = nC(n, n - r)
ll choose(ll n, ll r) {
  return is_valid(n, r) ? mul(fact[n], mul(inv[r], inv[n - r])) : 0LL;
}
 
ll stars_and_bars(ll stars, ll bars, bool repetition = true) {
  // combination with repetition
  if (repetition){ 
    return choose(stars + bars, bars);
  }
  // combination without repetition
  return choose(stars - 1, bars - 1);
}

void Accepted(){
  
  
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
