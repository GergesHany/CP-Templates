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

template < const ll MAX_VAL_OF_X = 1e9, bool Mode = 1 > struct LiChaoTree{

  // MAX_VAL_OF_X = maximum value of x
  // Mode = 1 for maximum, Mode = 0 for minimum

  static constexpr long long INF = numeric_limits < long long > :: max();

  struct Line{
    ll m, c;
    Line() {}
    Line(ll m, ll c) : m(m), c(c) {}
    ll evaluate(ll x) { return (m * x + c) * (Mode ? -1 : 1); }

    bool operator < (const Line &l) const {
      return m < l.m;
    }

    bool operator == (const Line &l) const {
      return m == l.m && c == l.c;
    }
  };

  struct Node {
    Line top;
    int left = -1, right = -1;
    
    Node() = default;
    Node (Line curr) : top(curr) {}
    Node(ll m, ll c) : top(Line(m, c)) {}

    ll evaluate(ll x) { return top.evaluate(x); }
  };


  vector < Node > Tree;

  LiChaoTree() {
    Tree.emplace_back(0, INF * (Mode ? -1 : 1));
  }

  void addline(ll m, ll c) {
    addline(Line(m, c), 0, MAX_VAL_OF_X + 1, 0);
  }

  void addline(Line toadd, ll l, ll r, int idx) {
    ll mid = (l + r) / 2;
    Line& top = Tree[idx].top;

    // If the line to add is better than the current line 
    if (top.evaluate(mid) > toadd.evaluate(mid)) {
      // Swap the line to add with the current line
      swap(top, toadd);
    }

    if (r - l <= 1) return;
    
    // If the line to add is better than the current line on the left side
    if (top.evaluate(l) > toadd.evaluate(l)) {
      // If there is no left child, create one
      if (Tree[idx].left == -1) {
        Tree[idx].left = Tree.size();
        Tree.emplace_back(top);
      }
      addline(toadd, l, mid, Tree[idx].left);
    }

    // If the line to add is better than the current line on the right side 
    else{
      // If there is no right child, create one
      if (Tree[idx].right == -1) {
        Tree[idx].right = Tree.size();
        Tree.emplace_back(top);
      }
      addline(toadd, mid, r, Tree[idx].right);
    }
  }

  ll query(ll x) {
    return min(Tree[0].evaluate(x), query(x, 0, MAX_VAL_OF_X + 1, 0)) * (Mode ? -1 : 1);
  }
  
  ll query(ll x, ll l, ll r, int idx) {
    if (idx == -1) return INF;
    if (x < l || x >= r || (r - l <= 1)) return Tree[idx].evaluate(x);
    ll mid = (l + r) / 2;
    auto L = query(x, l, mid, Tree[idx].left);
    auto R = query(x, mid, r, Tree[idx].right);
    return min({Tree[idx].evaluate(x), L, R});
  }

  void clear() {
    Tree.clear();
    Tree.emplace_back(0, INF * (Mode ? -1 : 1));
  }

};


void Accepted(){

  ll n;
  cin >> n;
 
  vector < ll > a(n), b(n);
  cin >> a >> b;
 
 
  /*
    y = mx + c
    dp[i] = dp[j] + b[j] * a[i]
     y    =   c   +  m   *   x
  */

  ll dp = -1;
  LiChaoTree < int(1e9), 0 > cht; 
  cht.addline(b[0], 0);
  for (int i = 1; i < n; i++){
    dp = cht.query(a[i]);
    cht.addline(b[i], dp);
  }
 
  cout << dp;
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
