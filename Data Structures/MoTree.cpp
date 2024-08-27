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

template < typename T = int, bool VAL_ON_EDGE = false > class MoTree {
public:
 
  static inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ordd = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ordd += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ordd;
  }
 
  struct Query {
    int64_t ord;
    int l, r, k, lca, queryIdx;
 
    Query(vector < T >& S, vector < T >& E, int L = 0, int R = 0, int QueryIdx = 0, int LCA = 0) {
      if (S[L] > S[R])
          swap(L, R);
      if (LCA == L) // if the two nodes are in the same subtree
          l = S[L] + VAL_ON_EDGE, r = S[R], lca = -1, queryIdx = QueryIdx;
      else
          l = E[L], r = S[R], lca = LCA, queryIdx = QueryIdx;
      calcOrder();
    }
 
    void calcOrder() {
      const int hilbert_pow = 19;
      // 2^hilbert_pow > 2 * N + 5
      ord = hilbertOrder(l, r, hilbert_pow, 0);
    }
 
    bool operator < (const Query& rhs) const {
      return ord < rhs.ord;
    }
  };
 
  MoTree(int N, int M, vector < vector < pair < T, T > > >& G, int root = 1) {
    n = N, m = M, adj = G, SqrtN = n / sqrt(m) + 1, timer = 1, ans = 0, LOG = 0;
    while((1 << LOG) <= n) LOG++;
 
    adj = G;
    answers = vector < T > (m);
    val = vector < T > (n + 5);
    FT = vector < int > (2 * n + 5);
    nodeVis = S = E = dep = vector < int > (n + 5);
    anc = vector < vector < int > > (n + 5, vector < int > (LOG));
 
    dfs(root, -1);
  }
 
  inline const vector < T > getAnswers(){
    return answers;
  }
 
  // solve the queries
  const inline void solve(){
    getData();
    solve_queries();
  }
 
  // set the values of the nodes
  inline void set_values(vector < T >& VAL){
    val = VAL;
  }
 
private:
  T ans;
  vector < Query > queries;
  vector < T > answers, val;
  vector < vector < int > > anc;
  vector < int > dep, S, E, FT, nodeVis;
  vector < vector < pair < T, T > > > adj;
  int curr_l, curr_r, n, m, SqrtN, timer, LOG;
 
 
  inline void getData() {
    for (int i = 0, u, v; i < m && cin >> u >> v; i++){
      queries.emplace_back(S, E, u, v, i, getLCA(u, v));
    }
  }
 
  inline void solve_queries() {
    sort(all(queries));
 
    curr_l = queries[0].l, curr_r = queries[0].l - 1;
 
    for (auto& q : queries) {
      moves(q);
 
      // if lca is -1 then the two nodes are in the same subtree
      if (~q.lca && !VAL_ON_EDGE) 
          add(q.lca);
      
      answers[q.queryIdx] = -1; 
      
      if (~q.lca && !VAL_ON_EDGE) 
          remove(q.lca);
    }
  }
 
  inline void dfs(int u, int p = -1) {
    S[u] = timer;
    FT[timer++] = u;
    for (auto& [v, w] : adj[u]) if (v != p) {
      anc[v][0] = u;
      dep[v] = dep[u] + 1;
      for (int bit = 1; bit < LOG; bit++)
          anc[v][bit] = anc[anc[v][bit - 1]][bit - 1];
      if (VAL_ON_EDGE) val[v] = w; // push down the edge value
      dfs(v, u);
    }
    E[u] = timer;
    FT[timer++] = u;
  }
 
  const int kthAncestor(int u, int k) {
    if (dep[u] < k)
        return -1;
    for (int bit = LOG - 1; bit >= 0; bit--)
        if (k & (1 << bit))
            u = anc[u][bit];
    return u;
  }
 
  const int getLCA(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    u = kthAncestor(u, dep[u] - dep[v]);
    if (u == v)
        return u;
    for (int bit = LOG - 1; bit >= 0; bit--) if (anc[u][bit] != anc[v][bit]){
      u = anc[u][bit], v = anc[v][bit];
    }          
    return anc[u][0];
  }
 
  inline void moves(Query& q) {
    while (curr_l > q.l) operation(--curr_l); // add
    while (curr_r < q.r) operation(++curr_r); // add
    while (curr_l < q.l) operation(curr_l++); // remove
    while (curr_r > q.r) operation(curr_r--); // remove
  }
 
  inline void add(int u){

  }
 
  inline void remove(int u){

  }
 
  inline void operation(int idx) {
    int u = FT[idx];
    nodeVis[u] ^= 1;
    if (nodeVis[u]) add(u);
    else remove(u);
  }
 
};

void Accepted(){
  
  
 
} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
