#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-8
#define sz(s) (int)(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";

int tt, tc;  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 2e3 + 5;
  
void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}
  
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}

template < typename T = int, bool Base = false > struct Lazy_Propagation {

  struct Node {
    T val = 0, update = 0;
    bool is_lazy = false;
    Node(T val = 0) : val(val) {}
    Node operator = (const T &other) {
      val = other;
      return *this;
    }
  };

  int size;
  vector < Node > tree;
  T defeault_value, lazy_default_value;

  void init(int n) {
    size = 1;
    while (size < n) size <<= 1;
    tree = vector < Node > (size << 1);
    defeault_value = 0, lazy_default_value = 0;
  }

  Lazy_Propagation(int n = 0) {
    init(n);
  }

  T Lazy_operation(const T &a, const T &b) {
    return b;
  }

  Node Tree_operation(const Node &a, const Node &b) {
    return Node(a.val + b.val);
  }

  void propagate(int idx, int lx, int rx) {
    if (tree[idx].is_lazy == false) return;
    tree[idx].val = Lazy_operation(tree[idx].val, tree[idx].update);
    if (lx != rx) {
      tree[idx << 1].is_lazy = tree[idx << 1 | 1].is_lazy = true;
      tree[idx << 1].update = Lazy_operation(tree[idx << 1].update, tree[idx].update);
      tree[idx << 1 | 1].update = Lazy_operation(tree[idx << 1 | 1].update, tree[idx].update);
    }
    tree[idx].is_lazy = false;
    tree[idx].update = lazy_default_value;
  }

  void build(vector < T > &a, int idx, int lx, int rx) {
    if ((Base && lx >= sz(a)) || (!Base && lx > sz(a))) return;
    if (lx == rx) return void(tree[idx] = a[lx - !Base]);
    int mid = lx + rx >> 1;
    build(a, idx << 1, lx, mid);
    build(a, idx << 1 | 1, mid + 1, rx);
    propagate(idx << 1, lx, mid), propagate(idx << 1 | 1, mid + 1, rx);
    tree[idx] = Tree_operation(tree[idx << 1], tree[idx << 1 | 1]);
  }

  void build(vector < T > &a) {
    build(a, 1, Base, size + Base - 1);
  }

  void update(int l, int r, T val, int idx, int lx, int rx) {
    propagate(idx, lx, rx);
    if (lx > r || rx < l) return;
    if (lx >= l && rx <= r) {
      tree[idx].is_lazy = true;
      tree[idx].update = Lazy_operation(tree[idx].update, val);
      propagate(idx, lx, rx);
      return;
    }
    int mid = lx + rx >> 1;
    update(l, r, val, idx << 1, lx, mid);
    update(l, r, val, idx << 1 | 1, mid + 1, rx);
    tree[idx] = Tree_operation(tree[idx << 1], tree[idx << 1 | 1]);
  }

  void update(int l, int r, T val) {
    update(l, r, val, 1, Base, size + Base - 1);
  }

  Node query(int l, int r, int idx, int lx, int rx) {
    propagate(idx, lx, rx);
    if (lx > r || rx < l) return defeault_value;
    if (lx >= l && rx <= r) return tree[idx];
    int mid = lx + rx >> 1;
    return Tree_operation(query(l, r, idx << 1, lx, mid), query(l, r, idx << 1 | 1, mid + 1, rx));
  }

  T query(int l, int r) {
    return query(l, r, 1, Base, size + Base - 1).val;
  }


};


void Accepted(){
  

}

int main(){ 

  tt = 1;
  Gerges_Hany();
  // cin >> tt;
  while(tt--) 
    Accepted();
  
  Time;
  return 0;
}
