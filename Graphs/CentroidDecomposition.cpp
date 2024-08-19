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
const int mod = 1e9 + 7, N = 2e5 + 5;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}

template < typename T = int > class CentroidDecomposition{

public:
  int n, treeRoot;
  vector < T > SubtreeSz;
  vector < bool > isCentroid;
  vector < vector < T > > adj;

  CentroidDecomposition(int N, vector < vector < T > > &G, int Root = 1) : n(N), adj(G){
    treeRoot = Root;
    SubtreeSz = vector < T > (n + 5, 0);
    isCentroid = vector < bool > (n + 5, 0);
    dfs_sz(treeRoot, -1);
  }
  
  const inline int centroid(int u, int p){
    return dfs_centroid(u, p, dfs_sz(u, p));
  }

  inline void Decompose(){
    decompose(treeRoot, -1);
  }
 
private:
  inline ll dfs_sz(int u, int p){
    SubtreeSz[u] = 1;
    for (int v : adj[u]) if (v != p && !isCentroid[v]) SubtreeSz[u] += dfs_sz(v, u);
    return SubtreeSz[u];
  }

  const int dfs_centroid(int u, int p, int n){
    for (int v : adj[u]) if (v != p && !isCentroid[v] && SubtreeSz[v] > n / 2) return dfs_centroid(v, u, n);
    return u;
  }
  
  void decompose(int u, int p){
    int n = dfs_sz(u, p);
    int centroid = dfs_centroid(u, p, n);
    if (p == -1) p = centroid;
    isCentroid[centroid] = 1;
    for (int v : adj[centroid]) if (!isCentroid[v]) decompose(v, centroid);
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