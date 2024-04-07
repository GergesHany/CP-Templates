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

template < typename T = int > struct Tree_Diameter{

  int n;
  vector < T > dist, parent;
  vector < vector < T > > adj;

  Tree_Diameter(int _n = 0) : n(_n), adj(n + 1), dist(n + 1), parent(n + 1) {}

  void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void dfs(int u, int p = -1, T d = 0){
    dist[u] = d;
    parent[u] = p;
    for(auto v : adj[u]) if (v != p) dfs(v, u, d + 1);
  }

  pair < T, int > diameter(){
    dfs(1);
    int farthest = 1;
    for(int i = 1; i <= n; i++){
      if(dist[i] > dist[farthest]) farthest = i;
    }

    dfs(farthest);
    T diameter = 0;
    for(int i = 1; i <= n; i++) diameter = max(diameter, dist[i]);
    return {diameter, farthest};
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