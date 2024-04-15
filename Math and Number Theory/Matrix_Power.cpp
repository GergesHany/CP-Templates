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
const int mod = 1e9 + 7, N = 1e2 + 5;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}

template <typename T, int N, T MOD > struct matrix {
  
  vector < vector < T > > mat;
  matrix() : mat(N, vector < T > (N)) {}

  matrix operator*(const matrix& b) {
    matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += mat[i][k] * b.mat[k][j];
                c.mat[i][j] %= MOD;
            }
        }
    }
    return c;
  }
};

template <typename Matrix, typename T > Matrix power(Matrix b, T p) {
  Matrix res;
  for (int i = 0; i < sz(res.mat); ++i) res.mat[i][i] = 1;
  while (p) {
      if (p & 1) {
          res = res * b;
      }
      b = b * b;
      p >>= 1;
  }
  return res;
}

vector < vector < ll > > Trans = {
  {1, 4, 7}, 
  {2, 5, 8}, 
  {3, 6, 9}
};

void Accepted(){
  
  ll n;
  cin >> n;

  matrix < ll, 3, mod > base;
  base.mat = Trans;     

  matrix < ll, 3, mod > res = power(base, n - 1);

  ll ans = 0;
  for (auto &x : res.mat) for (auto &y : x) ans = (ans + y) % mod;
  
  cout << ans << '\n';

} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
  }

  tt = tc = 1; cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}