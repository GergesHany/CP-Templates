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

int color[N];
template < typename T = int > struct DSU_ON_TREE {
   
  int n, timer;
  map < T, T > f;
  vector < vector < T > > g;
  vector < T > p, sub, tin, tout, vertex, ans;
  
  DSU_ON_TREE(int _n, vector < vector < T > > G) : n(_n), g(G){
    p = sub = tin = tout = vertex = ans = vector < T > (n + 5);
    pre(1);
    dfs(1, 1);
  }

  inline void rem(T v) {
    --f[color[v]];
    if (f[color[v]] == 0) f.erase(color[v]);
  }

  inline void add(T v) {
    ++f[color[v]];
  }

  inline void solve_queries(T v) {
    ans[v] = f.size();
  }

  inline T pre(T v) {
    tin[v] = ++timer;
    vertex[tin[v]] = v;
    sub[v] = 1;
    for (auto& u : g[v]) if (u != p[v]) {
      p[u] = v;
      sub[v] += pre(u);
    }
    tout[v] = timer;
    return sub[v];
  }

  inline void dfs(T v, bool keep) {
    T big = -1; // big child 

    // find the big child (the child with the largest subtree size)
    for (auto& u : g[v]) {
      if (u != p[v] && (big == -1 || sub[u] > sub[big])) {
        big = u;
      }
    }

    // dfs on small children and clear the big child
    for (auto& u : g[v]) if (u != p[v] && u != big) dfs(u, 0);
    
    // dfs on the big child
    if (big != -1) dfs(big, 1);
    
    // add the big child to the current segment
    for (auto& u : g[v]) {
      if (u != p[v] && u != big) {
        for (T i = tin[u]; i <= tout[u]; i++) add(vertex[i]);
      }
    }

    add(v);
    solve_queries(v);
    if (!keep) for (T i = tin[v]; i <= tout[v]; i++) rem(vertex[i]);
  }

  inline bool is_ancestor(T u, T v) {
    return (tin[u] <= tin[v] && tin[v] <= tout[u]);
  }

};

void Accepted(){
  
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
      cin >> color[i];
  }

  vector < vector < int > > g(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v; 
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  DSU_ON_TREE < int > dsu(n, g);

  for (int i = 1; i <= n; i++) {
    cout << dsu.ans[i] << ' ';
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