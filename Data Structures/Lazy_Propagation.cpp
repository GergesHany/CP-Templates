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

/**
 * Represents the type of lazy update being done.
 * NONE = if there's no lazy update to be performed.
*/

enum QueryType { ADD, SET, NONE };
struct Query {

  QueryType type = NONE;
  ll val = 0;

};

/*

 * T = tree node type, which will be long long
 * We use the Query struct to manage updates.

*/

template < class T > class Lazysegment_tree {

private:
  int size;
  T DEFAULT = 0;
  vector < Query > lazy;  // lazy[i] = lazy update for the range
  vector < T > tree;      // tree[i] = Tree_operation of this node's range


  /** @return result of joining two tree nodes together */

  inline T Tree_operation(T a, T b) { return a + b; }

  /** builds the segtree nodes */
  void build(int v, int l, int r, const vector<T> &a) {
    if (l == r) {
      tree[v] = a[l];
    } else {
      int m = (l + r) / 2;
      build(2 * v, l, m, a);
      build(2 * v + 1, m + 1, r, a);
      tree[v] = Tree_operation(tree[2 * v], tree[2 * v + 1]);
    }
  }

  /** applies lazy update to t[v], places update at lz[v] */
  void apply(int v, int len, const Query &x) {
    if (x.type == ADD) {
      // if lazy[v]'s type is NONE or ADD, then we add to the range
      // otherwise, we add to our lazy set value
      if (lazy[v].type != SET) {
        lazy[v] = Query{ADD, lazy[v].val + x.val};
      } else {
        lazy[v] = Query{SET, lazy[v].val + x.val};
      }
       tree[v] += x.val * len;
      } else if (x.type == SET) {
        // lazy set overrides any previous update
        tree[v] = x.val * len;
        lazy[v] = x;
     }
  }

  /** pushes down lazy update to children of v */
  void push_down(int v, int l, int r) {
    if (lazy[v].type != NONE && l != r) {
      int m = (l + r) / 2;
      apply(2 * v, m - l + 1, lazy[v]);
      apply(2 * v + 1, r - m, lazy[v]);
    }
    lazy[v] = Query{NONE, 0};
  }


  void range_update(int v, int l, int r, int ql, int qr, const Query &x) {
    if (qr < l || ql > r) return;
    if (ql <= l && r <= qr) {
      apply(v, r - l + 1, x);
    } else {
      push_down(v, l, r);
      int m = (l + r) / 2;
      range_update(2 * v, l, m, ql, qr, x);
      range_update(2 * v + 1, m + 1, r, ql, qr, x);
      tree[v] = Tree_operation(tree[2 * v], tree[2 * v + 1]);
    }
  }

  T range_sum(int v, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return DEFAULT; 
    if (l >= ql && r <= qr) return tree[v];
    push_down(v, l, r);
    int m = (l + r) / 2;
    auto L = range_sum(2 * v, l, m, ql, qr);
    auto R = range_sum(2 * v + 1, m + 1, r, ql, qr);
    return Tree_operation(L, R);
  }

public:
  inline void init(const int n){
    size = 1;
    while (size < n) size *= 2;
    tree.assign(2 * size, 0);
    lazy.assign(2 * size, Query{NONE, 0});
  }

  Lazysegment_tree(const int n, T DEFAULT_ = 0) : DEFAULT(DEFAULT_) {
    init(n);
  }

  Lazysegment_tree(const vector < T > &a, T DEFAULT_ = 0) : DEFAULT(DEFAULT_) {
    init(sz(a));
    build(1, 0, size - 1, a);
  }

  /** updates [ql, qr] with the update x */
  inline void range_update(int ql, int qr, const Query &x) {
    range_update(1, 0, size - 1, ql, qr, x);
  }

  /** sum of array values on [ql, qr] */
  inline T query(int ql, int qr) { return range_sum(1, 0, size - 1, ql, qr); }

  inline T operator[](int i) { return query(i, i); }
  
  // ** add and update range [l, r] to x */
  inline void add(int l, int r, T x) { range_update(l, r, Query{ADD, x}); }
  inline void update(int l, int r, T x) { range_update(l, r, Query{SET, x}); }

  // ** add and update single index i to x */
  inline void add(int i, T x) { add(i, i, x); }
  inline void update(int i, T x) { update(i, i, x); }

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
