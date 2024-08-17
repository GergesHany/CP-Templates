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


template < typename T = int > class Partial_2D{

public:
  int N, M;
  vector < vector < T > > P;

  Partial_2D(int n, int m){
    N = n, M = m;
    P = vector < vector < T > > (N + 5, vector < T > (M + 5, 0));
  }

  const inline T operator () (int Lx, int Rx, int Ly, int Ry){
    return query(Lx, Rx, Ly, Ry);
  }

  const inline vector < T >& operator [] (int x) const {
    return P[x];
  }

  const inline void add_rectangle(int Lx, int Rx, int Ly, int Ry, T val){
    add(Lx, Rx, Ly, Ry, val);
  } 

  const inline void build() {
    buildPrefixSum();
  }

private:
  inline void buildPrefixSum(){
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++)
        P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
  }

  inline void add(int Lx, int Rx, int Ly, int Ry, T val){
    P[Lx][Ly] += val;
    P[Rx + 1][Ly] -= val;
    P[Lx][Ry + 1] -= val;
    P[Rx + 1][Ry + 1] += val;
  }

  inline T query(int Lx, int Rx, int Ly, int Ry){
    return P[Rx][Ry] - P[Lx - 1][Ry] - P[Rx][Ly - 1] + P[Lx - 1][Ly - 1];
  }

};

void Accepted(){
  

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
