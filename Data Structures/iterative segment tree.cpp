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

// iterative segment tree
template < typename T = int > struct segment_tree {
  
  int n;
  T Default;
  vector < T > Tree;
  function < T (T, T) > F;

  segment_tree(int _n, T _Default, function < T (T, T) > _F) : n(_n), F(_F) {
    Default = _Default;
    Tree = vector < T > (4 * n + 5, Default);
  }

  void update(int i, T val) {
    for (Tree[i += n] = val; i >>= 1;) {
      Tree[i] = F(Tree[i << 1], Tree[i << 1 | 1]);
    }
  }

  T query(int l, int r) {
    T res = Default;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) res = F(res, Tree[l++]);
      if (!(r & 1)) res = F(res, Tree[r--]);
    }
    return res;
  }

  void build(vector < T > &v) {
    for (int i = 0; i < n; ++i) Tree[i + n] = v[i];
    for (int i = n - 1; i > 0; --i) Tree[i] = F(Tree[i << 1], Tree[i << 1 | 1]);
  }

 // segment_tree < int > st(n, (1LL << 31) - 1, [&](int a, int b) { return a & b; });

};


void Accepted(){
  
  
 
} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
  }

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}