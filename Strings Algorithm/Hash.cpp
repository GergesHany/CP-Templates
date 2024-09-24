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
template < bool Base = false > struct Hash {

  static bool done;
  vector < ll > h1, h2;
  static constexpr array < int, 2 > p = {31, 313};
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

  template < typename T > inline const void calc(const T& v){ // {string, vector}
    int n = v.size();
    h1 = h2 = vector < ll > (n + 5, 1);
    for(int i = 1; i <= n; i++) {
      h1[i] = add(v[i - !Base], mul(h1[i - 1], p[0], mods[0]), mods[0]);
      h2[i] = add(v[i - !Base], mul(h2[i - 1], p[1], mods[1]), mods[1]);
    }
  }
 
  template < typename T > Hash(const T& v){
    if (!done) 
      precumpute(); // precompute the powers of p
    calc(v);
  }
 
  // calculate the hash of the position pos
  const inline pair < ll, ll > at(const ll &pos){
    return get_hash(pos, pos);
  }
 
  // calculate the hash of the substring s[l..r]
  const inline pair < ll, ll > get_hash(const int &l, const int &r) {
    // hash of s[l..r] based on p1
    ll F = h1[r];
    F = sub(F, mul(h1[l - 1], pw1[r - l + 1], mods[0]), mods[0]);
    
    // hash of s[l..r] based on p1
    ll S = h2[r];
    S = sub(S, mul(h2[l - 1], pw2[r - l + 1], mods[1]), mods[1]);
    return {F, S};
  }
 
  const inline bool is_same(const int &l1, const int &r1, const int &l2, const int &r2){
    return get_hash(l1, r1) == get_hash(l2, r2);
  }
  
  // merge the hashes of two substrings s1[l1..r1] and s2[l2..r2]
  const inline pair < ll, ll > merge(const int &l1, const int &r1, const int &l2, const int &r2) {
    auto h1 = get_hash(l1, r1), h2 = get_hash(l2, r2);
    ll F = add(mul(h1.first, pw1[r2 - l2 + 1], mods[0]), h2.first, mods[0]);
    ll S = add(mul(h1.second, pw2[r2 - l2 + 1], mods[1]), h2.second, mods[1]);
    return {F, S};
  }

  #undef add
  #undef mul
  #undef sub
 
};

// static member initialization
template < bool Base> bool Hash < Base > :: done = false;

void Accepted(){
  
  
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
