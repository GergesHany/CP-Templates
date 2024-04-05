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


template < typename T = int > struct segment_tree {
  
  int n;
  T Default;
  vector < T > Tree;
  function < T (T, T) > F;
 
  segment_tree() = default;
 
  segment_tree(int _n, T _Default, function < T (T, T) > _F) : n(_n), Default(_Default), F(_F) {
    Tree = vector < T > (4 * n + 5, Default);
  }
 
  void update(int i, T val) {
    for (Tree[i += n] = val; i >>= 1;) Tree[i] = F(Tree[i << 1], Tree[i << 1 | 1]);
  }
 
  T query(int l, int r) {
    T res = Default;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) res = F(res, Tree[l++]);
      if (!(r & 1)) res = F(res, Tree[r--]);
    }
    return res;
  }
 
 // segment_tree < int > st(n, (1LL << 31) - 1, [&](int a, int b) { return a & b; });
 
};
 
 
template < typename T = int, const int VAL_ON_EDGE = 0 > struct HLD {
  
  // VAL_ON_EDGE = 0, if value on node, 1 if value on edge
 
  T DEFAULT;
  int nxt_pos;
  segment_tree < T > st;
  vector < vector < T > > adj;
  vector < T > depth, parent, root, pos, SubtreeSz, child;
 
  HLD(int n, vector < vector < T > > &_adj) : nxt_pos(1), adj(_adj) {
    DEFAULT = 1e10;
    depth = parent = root = pos = SubtreeSz = child = vector < T > (n + 1, 0);
    dfs(1); // init dfs
    decompose(1); // init hld
    st = segment_tree < T > (n + 1, DEFAULT, [&](T a, T b) { return min(a, b); });
  }
 
  // dfs to calculate depth, parent, subtree size, child of each node
  inline void dfs(T u, T p = -1, T d = 0) {
    depth[u] = d, parent[u] = p, SubtreeSz[u] = 1;
    for (auto v : adj[u]) if (v != p) {
      dfs(v, u, d + 1);
      SubtreeSz[u] += SubtreeSz[v];
      if (SubtreeSz[v] > SubtreeSz[child[u]]) child[u] = v;
    }
  }
 
  // decompose the tree into chains
  inline void decompose(T u, bool newChain = true) {
    root[u] = newChain ? u : root[parent[u]];
    pos[u] = nxt_pos++;
    if (child[u]) decompose(child[u], false);
    for (auto v: adj[u]) if (v != parent[u] && v != child[u]) decompose(v, true);
  }
 
  // make u lower 
  inline void makeULower(T &u, T &v) {
    if (depth[root[u]] < depth[root[v]] || (depth[root[u]] == depth[root[v]] && pos[u] < pos[v])) {
      swap(u, v);
    }
  }
 
  // move up the chain and also change the next position
  inline pair < T, T > moveUp(T &u) {
    pair < T, T > res = {pos[root[u]], pos[u]};
    u = parent[root[u]];
    return res;
  }
 
  // query from u to v
  inline vector < pair < T, T > > queryPath(T u, T v) {
    vector < pair < T, T > > ans;
    while(root[u] != root[v]) {
      makeULower(u, v);
      ans.push_back(moveUp(u));
    }
 
    makeULower(u, v);
    if (!VAL_ON_EDGE) ans.push_back({pos[v], pos[u]}); // value on node
    else ans.push_back({pos[v] + 1, pos[u]}); // don't include the root node
    return ans;
  }
  
  // update the value of node u
  inline void updateNode(T u, T val) {
    st.update(pos[u], val);
  }
 
  // query the value from u to v
  inline T query(T u, T v) {
    T res = DEFAULT;
    for (auto [l, r] : queryPath(u, v)) res = min(res, st.query(l, r));
    return res;
  }
 
  // lca of u and v
  inline T lca(T u, T v) {
    while (root[u] != root[v]) {
      if (depth[root[u]] < depth[root[v]]) swap(u, v);
      u = parent[root[u]];
    }
    return depth[u] < depth[v] ? u : v;
  }
 
  // get the child of u which is not v
  inline T getChild(T u, T v) {
    return parent[u] == v ? u : v;
  }
  
  // update the value of edge u-v
  inline void updateEdge(T u, T v, T val) {
    st.update(pos[getChild(u, v)], val);
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
