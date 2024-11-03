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

struct RollbackDSU {
  struct Change {
    int node, old_par, old_rank;
  };
 
  vector < int > par, rank;
  stack < Change > history;
 
  RollbackDSU(int n) : par(n + 5), rank(n + 5, 0) {
    iota(all(par), 0);
  }
 
  int find(int x) {
    return par[x] == x ? x : find(par[x]);
  }

  void merge(int rootX, int rootY) {
    if (rank[rootX] > rank[rootY]) {
      par[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      par[rootX] = rootY;
    } else {
      par[rootY] = rootX;
      rank[rootX]++;
    }
  };
 
  bool unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false; // already in the same set
 
    history.push({rootY, par[rootY], rank[rootY]});
    history.push({rootX, par[rootX], rank[rootX]});

    merge(rootX, rootY); 
    return true;
  }
 
  void rollback(int x) {
    while (sz(history) > x) {
      Change lastChange = history.top();
      history.pop();
      par[lastChange.node] = lastChange.old_par;
      rank[lastChange.node] = lastChange.old_rank;
    }
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