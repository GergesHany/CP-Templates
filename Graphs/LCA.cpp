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

template < typename T = int > struct LCA {
  
  T N, LOG = 0;
  vector < T > depth;
  vector < vector < T > > adj, anc;
 
  LCA(T n = 0){
    N = n + 5;
    depth = vector < T > (N);
    while ((1 << LOG) <= N) ++LOG;
    adj = vector < vector < T > > (N);
    anc = vector < vector < T > > (N, vector < T > (LOG));
  }
 
  inline void addEdge(T u, T v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  inline void dfs(T u, T p){
    anc[u][0] = p;
    for (T i = 1; i < LOG; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (T v : adj[u]) if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }
 
  inline T kth_ancestor(T u, T k){
    if (k < 0 || depth[u] < k) return -1;
    for (T i = 0; i < LOG; i++) if (k & (1 << i)) u = anc[u][i];
    return u;
  }
 
  inline T lca(T u, T v){
    if (depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (T i = LOG - 1; i >= 0; i--) if (anc[u][i] != anc[v][i]) {
      u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
  }
 
  inline T dist(T u, T v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
 
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
