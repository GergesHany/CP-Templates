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

class Sparse_Table{
 
private:
 
  int LOG;
  vector < int > log_table;
  function < int(int, int) > func;
  vector < vector < int > > table;
 
  inline void Build_Table(const vector < int > &vec){
   for(int i = 0; i < sz(vec); i++) table[0][i] = vec[i];
    for(int j = 1; j <= LOG; j++){
      for(int i = 0; i + (1 << j) <= sz(vec); i++){
        table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
 
  inline void init(const int n){
    LOG = 32 - __builtin_clz(n);
    log_table = vector < int > (n + 1);
    for(int i = 2; i <= n; i++) log_table[i] = log_table[i >> 1] + 1;
    table = vector < vector < int > > (LOG + 1, vector < int > (n));
  }
 
  // O(1) query (not overlapping)
  const inline int query_1(int l, int r){
    int j = log_table[r - l + 1];
    return func(table[j][l], table[j][r - (1 << j) + 1]);
  }
 
public:
 
  const inline int query(int l, int r){
    return query_1(l, r);
  }

  Sparse_Table() = default;
 
  Sparse_Table(const vector < int > &vec, function < int(int, int) > f) : func(f) {
    init(sz(vec));
    Build_Table(vec);
  }
 
  // Sparse_Table < ll, ll > mn(a, 1e18, [&](ll a, ll b){ return min(a, b); });
 
};


struct LCA {
  
  int N, LOG;
  Sparse_Table st;
  vector < vector < int > > adj, anc;
  vector < int > depth, euler, first;
   
  void dfs(int u, int p, int d){
    depth[u] = d;
    euler.push_back(u);
    first[u] = sz(euler) - 1;

    anc[u][0] = p; 
    for(auto v : adj[u]) if (v != p) {
      anc[v][0] = u;
      for(int i = 1; i < LOG; i++) anc[v][i] = anc[anc[v][i - 1]][i - 1];

      dfs(v, u, d + 1);
      euler.push_back(u);
    }
  }
  
  LCA(const vector < vector < int > > &adj, int root = 1) : adj(adj), N(sz(adj) + 1){
    LOG = 1;
    while((1 << LOG) <= N) LOG++;
    depth = first = vector < int > (N);
    anc = vector < vector < int > > (N, vector < int > (LOG + 1));
    
    dfs(root, root, 0);
    st = Sparse_Table(euler, [&](int a, int b){ return depth[a] < depth[b] ? a : b; });
  }

  int lca(int u, int v){
    if(first[u] > first[v]) swap(u, v);
    return st.query(first[u], first[v]);
  }

  int distance(int u, int v){
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }

  bool is_ancestor(int u, int v){ return lca(u, v) == u; }

  int kth_ancestor(int u, ll k){
    if (depth[u] < k) return -1;
    for(int i = 0; i < LOG; i++) if((k >> i) & 1) u = anc[u][i];
    return u;
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
