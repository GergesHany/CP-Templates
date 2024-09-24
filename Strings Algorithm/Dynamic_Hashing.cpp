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

ll pw1[N], pw2[N];

template < bool Base = false > struct Dynamic_Hashing {

  ll h1, h2, len;
  deque < char > hash;

  static bool done;
  static constexpr array < int, 2 > p = {31, 313};
  static constexpr array < int, 2 > inv = {129032259, 415335467};
  static constexpr array < int, 2 > mods = {1000000007, 1000000009};

  #define add(a, b, m) (((a % m) + (b % m)) % m)
  #define mul(a, b, m) (((a % m) * (b % m)) % m)
  #define sub(a, b, m) ((((a % m) - (b % m)) + m) % m)

  inline static constexpr void precumpute() {
    done = true;
    for (int i = 0; i < N; i++) pw1[i] = pw2[i] = 1;
    for (int i = 1; i < N; ++i) {
      pw1[i] = mul(pw1[i - 1], p[0], mods[0]);
      pw2[i] = mul(pw2[i - 1], p[1], mods[1]);
    }    
  }

  Dynamic_Hashing() : h1(0), h2(0), len(0) {
    if (!done) precumpute();
  }

  template < typename T > Dynamic_Hashing(const T& v){
    h1 = h2 = len = 0;
    if (!done) 
      precumpute(); // precompute the powers of p

    for (auto &c: v) push_back(c);
  }

  const inline int get(char c){
    return c - 'a' + 1;
  }

  inline void push_back(char c){
    len++;
    hash.push_back(c);
    h1 = add(1LL * h1 * p[0] % mods[0], get(c), mods[0]);
    h2 = add(1LL * h2 * p[1] % mods[1], get(c), mods[1]);
  }

  inline void pop_back(){
    if (len == 0) return;

    h1 = sub(h1, get(hash.back()), mods[0]);
    h2 = sub(h2, get(hash.back()), mods[1]);

    h1 = mul(h1, inv[0], mods[0]);
    h2 = mul(h2, inv[1], mods[1]);

    len--;
    hash.pop_back();
  }

  inline void push_front(char c){
    hash.push_front(c);
    h1 = add(1LL * get(c) * pw1[len] % mods[0], h1, mods[0]);
    h2 = add(1LL * get(c) * pw2[len] % mods[1], h2, mods[1]);
    len++;
  }

  inline void pop_front(){
    if (len == 0) return;

    len--;
    h1 = sub(h1, mul(get(hash.front()), pw1[len], mods[0]), mods[0]);
    h2 = sub(h2, mul(get(hash.front()), pw2[len], mods[1]), mods[1]);
    hash.pop_front();
  }

  const inline pair < ll, ll > get_Hash() const {
    return {h1, h2};
  }

  // merge two hashes 
  const inline pair < ll, ll > merge(const Dynamic_Hashing &prefix, const Dynamic_Hashing &suffix) {
    ll F = add(suffix.h1, mul(prefix.h1, pw1[suffix.len], mods[0]), mods[0]);
    ll S = add(suffix.h2, mul(prefix.h2, pw2[sz(suffix.hash)], mods[1]), mods[1]);
    return {F, S};
  }

  #undef add
  #undef mul
  #undef sub

};

// static member initialization
template < bool Base > bool Dynamic_Hashing < Base > :: done = false;

void Accepted(){
  
  
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
