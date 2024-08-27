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

// BIT based-one
template < typename T = long long > struct BIT_2D{
  
  int n, m;
  vector < vector < T > > Tree;
  
  explicit BIT_2D(int N, int M) : n(N), m(M), Tree(n, vector < T > (m)) {}
  
  void add(int x, int y, T v){
    ++y;  
    for (++x; x <= n; x += x & -x)
      for (int j = y; j <= m; j += j & -j)
        Tree[x - 1][j - 1] += v;
  }
  
  const inline T get(int x, int y){
    y++;
    T v = 0;
    for (++x; x > 0; x -= x & -x)
      for (int j = y; j > 0; j -= j & -j)
        v += Tree[x - 1][j - 1];
    return v;
  }
  
  const inline T get_rec(int x1, int y1, int x2, int y2){
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
  }

  const inline T point(int x, int y){
    return get_rec(x, y, x, y);
  }

};

void Accepted(){
  
  
 
} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}