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

struct Node {
  
  bool is_lazy;
  ll val, update;
  
  Node(ll V = 0) : val(V), update(false), is_lazy(false) {}

  Node operator = (const ll &other){
    this -> val = other;
    return *this;
  }
};

template < typename T = int, const bool Base = 0 > struct Lazy_Propagation {
  
  int size;
  vector < Node > Tree;
  T query_default, init_default;

  #define LEFT (idx << 1)
  #define RIGHT ((idx << 1) | 1)
  
  // the function that will be used to update the Tree
  function < T(T, T) > Lazy_operation;

  // the function that will be used to query on the Tree
  function < Node(Node, Node) > Tree_operation;
 
  inline void intial(int n, T qd = 0, T id = 0){
    size = 1;
    while(size <= n) size *= 2;
    query_default = qd, init_default = id;
    Tree = vector < Node > (2 * size, Node(init_default));
  }
 
  explicit Lazy_Propagation(int n){
    intial(n);
  }
 
  inline void propagate(int idx, int lx, int rx){
    if(!Tree[idx].is_lazy) return;
    Tree[idx].val = Lazy_operation(Tree[idx].val, (rx - lx + 1) * Tree[idx].update);
    if(lx != rx){
      Tree[LEFT].update = Lazy_operation(Tree[LEFT].update, Tree[idx].update);
      Tree[RIGHT].update = Lazy_operation(Tree[RIGHT].update, Tree[idx].update);
      Tree[LEFT].is_lazy = Tree[RIGHT].is_lazy = true;
    }
    Tree[idx].update = init_default, Tree[idx].is_lazy = false;
  }
 
  inline void update_lazy(int idx, T v){
    Tree[idx].update = Lazy_operation(Tree[idx].update, v);
    Tree[idx].is_lazy = true;
  }
 
  inline void build(const vector < T >& nums, int idx, int lx, int rx){
    propagate(idx, lx, rx);
    if(Base ? lx >= sz(nums) : lx > sz(nums)) return;
    if(rx == lx) Tree[idx] = nums[lx - !Base];
    else {
      int mx = (rx + lx) / 2;
      build(nums, LEFT, lx, mx), build(nums, RIGHT, mx + 1, rx);
      propagate(LEFT, lx, mx), propagate(RIGHT, mx + 1, rx);
      Tree[idx] = Tree_operation(Tree[LEFT], Tree[RIGHT]);
    }
  }
 
  inline void build(const vector < T >& nums){
    build(nums, 1, 1, size);
  }
 
  inline void update(int l, int r, T v, int idx, int lx, int rx){
    propagate(idx, lx, rx);
    if(lx >= l && rx <= r) return update_lazy(idx, v);
    if(lx > r || rx < l) return;
    int mx = (lx + rx) / 2;
    update(l, r, v, LEFT, lx, mx), update(l, r, v, RIGHT, mx + 1, rx);
    propagate(LEFT, lx, mx), propagate(RIGHT, mx + 1, rx);
    Tree[idx] = Tree_operation(Tree[LEFT], Tree[RIGHT]);
  }
 
 
  inline void update(int l, int r, T v){
    update(l, r, v, 1, 1, size);
  }
 
  Node query(int l, int r, int idx, int lx, int rx){
    propagate(idx, lx, rx);
    if(lx >= l && rx <= r) return Tree[idx];
    if(lx > r || rx < l) return query_default;
    int mx = (rx + lx) / 2;
    propagate(LEFT, lx, mx), propagate(RIGHT, mx + 1, rx);
    return Tree_operation(query(l, r, LEFT, lx, mx), query(l, r, RIGHT, mx + 1, rx));
  }
 
  inline T query(int l, int r){
    return query(l, r, 1, 1, size).val;
  }
 
  #undef LEFT
  #undef RIGHT
 
};

/*
  
  function < ll(ll, ll) > Lazy_operation = [&](ll a, ll b) -> ll { return b; };
  function < Node(Node, Node) > Tree_operation = [&](Node a, Node b) -> Node {
    return Node(a.val + b.val);
  };

  Lazy_Propagation < ll > seg(n);
  seg.Lazy_operation = Lazy_operation;
  seg.Tree_operation = Tree_operation;
  seg.build(a);

*/

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
