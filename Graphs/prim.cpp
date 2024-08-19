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


template < typename T = int > struct Prim {
  
  struct Edge{
    T v, w;
    Edge(T v = 0.0, T w = 0.0) : v(v), w(w) {}
    bool operator < (const Edge &o) const { return w > o.w; }
  };
  
  vector < int > vis, par;
  vector < vector < Edge > > adj;

  inline void add_edge(T u, T v, T w){
    adj[u].push_back({v, w});
  }

  Prim(T n = 0, T m = 0, bool bidirectional = false) : adj(n + 1), vis(n + 1) {
    par = vector < int > (n + 1, -1);
    for (T i = 0, u, v, w; i < m and cin >> u >> v >> w; ++i){
      add_edge(u, v, w);
      if (bidirectional) add_edge(v, u, w);
    }
  }

  // return the minimum spanning tree cost
  inline T mst(T source){
    T ans = 0.0;
    priority_queue < Edge > q;
    q.push({source, 0.0});
    while (sz(q)){
      Edge e = q.top(); q.pop();
      if (vis[e.v]) continue;
      vis[e.v] = 1, ans += e.w;
      for (Edge &u : adj[e.v]){
        if (!vis[u.v]) q.push(u), par[u.v] = e.v;
      }
    }
    return ans;
  }
  
  // return the minimum spanning tree edges
  inline vector < pair < T, T > > getTree(){
    if (par == vector < T > (sz(par), -1)) mst(1);
    vector < pair < T, T > > edges;
    for (int i = 1; i < sz(par); i++) if (par[i] != -1) edges.push_back({par[i], i});
    return edges;
  }

};

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
