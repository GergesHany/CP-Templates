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

template < typename T = int, bool B = 0 > struct Hash_SegmentTree {
 
  int n, size;
  vector < pair < T, T > > tree;
  const int p1 = 313, p2 = 1013;
  vector < T > pow1, pow2, inv1, inv2;
  const int m1 = 1e9 + 7, m2 = 1e9 + 9;
 
  #define LEFT (idx << 1)
  #define RIGHT ((idx << 1) | 1)
 
  // {pow(p1, m1 - 2, m1), pow(p2, m2 - 2, m2)}
  T inv1_val = 492012783, inv2_val = 487660419; 
 
  function < T(T, T, T) > add = [&](T a, T b, T m){
    return (a + b) % m;
  };
 
  function < T(T, T, T) > mul = [&](T a, T b, T m){
    return (1LL * a * b) % m;
  };
 
  Hash_SegmentTree(int N = 0) : n(N) {
    size = 1;
    while(size < n) size *= 2;
    pair < T, T > DEFAULT = {0, 0};
    tree = vector < pair < T, T >  > (2 * size, DEFAULT);
    pow1 = pow2 = inv1 = inv2 = vector < T > (2 * size);
 
    pow1[0] = pow2[0] = inv1[0] = inv2[0] = 1;
 
    for(int i = 1; i < 2 * size; i++){
      pow1[i] = mul(pow1[i - 1], p1, m1), pow2[i] = mul(pow2[i - 1], p2, m2);
      inv1[i] = mul(inv1[i - 1], inv1_val, m1), inv2[i] = mul(inv2[i - 1], inv2_val, m2);
    }
  }
 
  inline pair < T, T > merge(const pair < T, T >& a, const pair < T, T >& b){
    return {add(a.first, b.first, m1), add(a.second, b.second, m2)};
  }
 
  inline void build(const vector < T >& nums, int idx, int lx, int rx){
    if(B ? lx >= sz(nums) : lx > sz(nums)) return;
    if(rx == lx){
      tree[idx] = {mul(nums[lx - !B], pow1[idx], m1), mul(nums[lx - !B], pow2[idx], m2)};
      return;
    }
    int mx = (rx + lx) / 2;
    build(nums, LEFT, lx, mx);
    build(nums, RIGHT, mx + 1, rx);
    tree[idx] = merge(tree[LEFT], tree[RIGHT]);
  }
 
  inline void build(const vector < T >& nums){
    build(nums, 1, 1, size);
  }
 
  inline void build(const string &s){
    vector < T > nums(sz(s));
    for(int i = 0; i < sz(s); i++) nums[i] = s[i] - 'a' + 1;
    build(nums);
  }
 
  inline void update(int index, T val, int idx, int lx, int rx){
    if(rx == lx){
      tree[idx] = {mul(val, pow1[idx], m1), mul(val, pow2[idx], m2)};
      return;
    }
    int mx = (lx + rx) / 2;
    if(index <= mx) update(index, val, LEFT, lx, mx);
    else update(index, val, RIGHT, mx + 1, rx);
    tree[idx] = merge(tree[LEFT], tree[RIGHT]);
  }
 
  inline void update(const int index, const T val){
    update(index, val, 1, 1, size);
  }
  
  inline pair < T, T > query(int l, int r, int idx, int lx, int rx){
    if(lx > r || l > rx) return {0, 0};
    if(lx >= l && rx <= r) return tree[idx];
    int mx = (lx + rx) / 2;
    return merge(query(l, r, LEFT, lx, mx), query(l, r, RIGHT, mx + 1, rx));
  }
 
  inline pair < T, T > query(const int l, const int r){
    auto [h1, h2] = query(l, r, 1, 1, size);
    return {mul(h1, inv1[l - 1], m1), mul(h2, inv2[l - 1], m2)};
  }
 
  #undef LEFT
  #undef RIGHT
 
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