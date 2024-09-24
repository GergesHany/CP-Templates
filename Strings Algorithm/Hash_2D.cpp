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

struct Hash_2D {

  int n, m;
  static bool done;
  vector < int > PWX, PWY;
  vector < vector < int > > hs;
  static constexpr int PX = 3731, PY = 2999, mod = 998244353;

  ll add(ll a, ll b) { return (a + b) % mod; }
  ll sub(ll a, ll b) { return (a - b + 2 * mod) % mod; }
  ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
  
  Hash_2D() = default;

  template < typename T > const inline void calc(const T & s){ // s = {string, vector}

    for (int i = 0; i < n; i++) PWX[i + 1] = mul(PWX[i], PX);
    for (int i = 0; i < m; i++) PWY[i + 1] = mul(PWY[i], PY);

    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++) 
        hs[i + 1][j + 1] = s[i][j];

    for (int i = 0; i <= n; i++) 
      for (int j = 0; j < m; j++) 
        hs[i][j + 1] = add(hs[i][j + 1], mul(hs[i][j], PY));

    for (int i = 0; i < n; i++) 
      for (int j = 0; j <= m; j++) 
        hs[i + 1][j] = add(hs[i + 1][j], mul(hs[i][j], PX));
  }

  template < typename T > Hash_2D(const T & s) {
    n = (int)s.size();
    m = (int)s[0].size();
    
    PWX.assign(n + 1, 1);
    PWY.assign(m + 1, 1);
    hs.assign(n + 1, vector < int > (m + 1, 0));
   
    calc(s);
  }

  const inline int get_hash() {
    return get_hash(1, 1, n, m);
  }
  
  // 1 - indexed
  const inline int get_hash(int x1, int y1, int x2, int y2) { 
    // check the range 
    assert(1 <= x1 && x1 <= x2 && x2 <= n);
    assert(1 <= y1 && y1 <= y2 && y2 <= m);
    
    x1--, y1--;
    int dx = x2 - x1, dy = y2 - y1;
    ll term1 = sub(hs[x2][y2], mul(hs[x2][y1], PWY[dy]));
    ll term2 = sub(hs[x1][y2], mul(hs[x1][y1], PWY[dy]));
    return sub(term1, mul(term2, PWX[dx]));
  }


};

void Accepted(){
  
  
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
