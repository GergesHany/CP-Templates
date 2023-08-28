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

template < typename T = int > struct Lazy_Propagation {
 
  struct Node{
    ll OPERATION, VALUE;
  };

  int size = 1;
  vector < Node > Tree;
  ll OUT_OF_RANGE = 0, NO_OPERATION = 0;

  ll merge(ll a, ll b, ll len){
    if (a == NO_OPERATION) return b * len;
    return a + (b * len);
  }

  ll Get(ll a, ll b){
    return (a + b);
  }

  void intial(int n){
    while(size < n) size *= 2;
    Tree = vector < Node > (size * 2);
  }

  void propagate(int x, int lx, int rx){
    if (Tree[x].OPERATION == NO_OPERATION || rx - lx == 1) return;
    int mid = (lx + rx) / 2;
    Tree[2 * x + 1].OPERATION = merge(Tree[2 * x + 1].OPERATION, Tree[x].OPERATION, 1);
    Tree[2 * x + 1].VALUE = merge(Tree[2 * x + 1].VALUE, Tree[x].OPERATION, mid - lx);
    Tree[2 * x + 2].OPERATION = merge(Tree[2 * x + 2].OPERATION, Tree[x].OPERATION, 1);
    Tree[2 * x + 2].VALUE = merge(Tree[2 * x + 2].VALUE, Tree[x].OPERATION, rx - mid);
    Tree[x].OPERATION = NO_OPERATION;
  }

  void update(int l, int r, ll v, int x, int lx, int rx){
    propagate(x, lx, rx);
    if (lx >= r || rx <= l) return;
    if (lx >= l && rx <= r){
      Tree[x].OPERATION = merge(Tree[x].OPERATION, v, 1);
      Tree[x].VALUE = merge(Tree[x].VALUE, v, rx - lx);
      return;
    }
    int mid = (lx + rx) / 2;
    update(l, r, v, 2 * x + 1, lx, mid);
    update(l, r, v, 2 * x + 2, mid, rx);
    Tree[x].VALUE = Get(Tree[2 * x + 1].VALUE, Tree[2 * x + 2].VALUE);
  }

  void update(int l, int r, ll v){
    update(l, r, v, 0, 0, size);
  }

  ll query(int l, int r, int x, int lx, int rx){
    propagate(x, lx, rx);
    if (lx >= r || rx <= l) return OUT_OF_RANGE;
    if (lx >= l && rx <= r) return Tree[x].VALUE;
    int mid = (lx + rx) / 2;
    ll left = query(l, r, 2 * x + 1, lx, mid);
    ll right = query(l, r, 2 * x + 2, mid, rx);
    return Get(left, right);
  }

  ll query(int l, int r){
    return query(l, r, 0, 0, size);
  }
 
};

void Accepted(){
  
  ll n, q;
  cin >> n >> q;
  Lazy_Propagation < ll > Tree;
  Tree.intial(n);

  while(q--){
    int type;
    cin >> type;
    if (type == 1){
      ll l, r, v;
      cin >> l >> r >> v;
      Tree.update(l, r, v);
    }else{
      int l, r;
      cin >> l >> r;
      cout << Tree.query(l, r) << "\n";
    }
  }

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
