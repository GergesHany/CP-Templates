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

// ans[u] = sum of distances from u to all other nodes in the tree
// subSz[u] = number of nodes in the subtree rooted at u 
// subAns[u] = sum of distances from u to all nodes in the subtree rooted at u
// ans[u] = subAns[u] + (p_ans + (total_nodes - subSz[u])) 
// where p_ans is the sum of distances from u to all nodes in the tree except the subtree rooted at u 


struct SumOfDist{

  int n;
  vector < vector < int > > g;
  vector < ll > ans, subAns, subSz;

  explicit SumOfDist(int _n) : n(_n), g(n + 1) {
    ans = subAns = subSz = vector < ll > (n + 1);
  }

  inline void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  inline void solve(){
    pre(1, 0);
    dfs(1, 0, 0, n);
  }
  
  inline ll operator [] (int u){
    return ans[u];
  }

  inline void pre(int u, int p){
    subSz[u] = 1; 
    for (auto & v: g[u]) if (v != p){
      pre(v, u);
      subSz[u] += subSz[v];
      subAns[u] += subSz[v] + subAns[v];
    } 
  }

  inline void dfs(int u, int p, ll p_ans, ll total_nodes){
    ans[u] = subAns[u] + (p_ans + (total_nodes - subSz[u]));
    for (auto & v: g[u]) if (v != p){
      dfs(v, u, ans[u] - (subAns[v] + subSz[v]), total_nodes);
    }
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
