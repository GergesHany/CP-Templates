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

template < typename T = int > struct Kruskal{

  struct Edge{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const Edge &other) const{
      return w < other.w;
    }
  };

  int n;
  vector < Edge > edges;
  vector < int > parent, size;

  inline void build(int m){
    edges = vector < Edge > (m);
    for (int i = 0, u, v, w; i < m and cin >> u >> v >> w; i++){
      --u, --v;
      edges[i] = Edge(u, v, w);
    }
  }

  Kruskal(int n = 0) : n(n){
    parent = vector < int > (n);
    size = vector < int > (n, 1);
    iota(all(parent), 0);
  }

  inline T find(int u){
    return parent[u] == u ? u : parent[u] = find(parent[u]);
  }

  inline bool merge(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return false; // u and v are already in the same set
    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    return true;
  }

  inline T mst(){
    T ans = 0;
    sort(all(edges));
    for (Edge &e : edges)
      if (merge(e.u, e.v)) ans += e.w;
    return ans;
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