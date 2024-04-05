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
  vector < vector < T > > anc, cost;
  vector < vector < pair < T, T > > > adj;

  LCA(T n = 0){
    N = n + 5;
    depth = vector < T > (N);
    while ((1 << LOG) <= N) ++LOG;
    adj = vector < vector < pair < T, T > > > (N);
    anc = vector < vector < T > > (N, vector < T > (LOG));
    cost = vector < vector < T > > (N, vector < T > (LOG, 1e10));
  }

  inline T operation(T a, T b){
    return min(a, b);
  }

  inline void addEdge(T u, T v, T w = 0){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  inline void dfs(T u, T p, T c){
    anc[u][0] = p;
    cost[u][0] = c;

    for (int i = 1; i < LOG; i++) {
      anc[u][i] = anc[anc[u][i - 1]][i - 1];
      cost[u][i] = operation(cost[u][i - 1], cost[anc[u][i - 1]][i - 1]);
    }
    
    for (auto [v, w] : adj[u]) if (v != p) {
      depth[v] = depth[u] + 1;
      dfs(v, u, w);
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
      u = anc[u][i];
      v = anc[v][i];
    }
    return anc[u][0];
  }

  inline T get_cost(T u, T k){
    T ans = 1e10;
    for (T i = 0; i < LOG; i++) if (k & (1 << i)) {
      ans = min(ans, cost[u][i]);
      u = anc[u][i];
    }
    return ans;
  }

  inline T query(T u, T v){
    T Lca = lca(u, v);
    return operation(get_cost(u, depth[u] - depth[Lca]), get_cost(v, depth[v] - depth[Lca]));
  }

};

void Accepted(){

  int n, m; 
  cin >> n >> m;
  LCA < ll > T(n);
  for(int i = 0; i < m; i++){
    int u, v, w; 
    cin >> u >> v >> w;
    T.addEdge(u, v, w);
  }
  
  T.dfs(1, 1, 0);
  int q; cin >> q;
  while(q--){
    int u, v; 
    cin >> u >> v;
    cout << T.query(u, v) << '\n';
  }  

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
