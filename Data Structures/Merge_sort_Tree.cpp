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

int tc = 1;  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 2e5 + 5;
  
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

// merge sort tree is a segment tree that stores sorted array in each node

template < typename T = int > struct Merge_sort_Tree{

  int size;
  vector < vector < T > > Tree; 

  // merge two sorted arrays
  vector < T > merge(const vector < T >& a, const vector < T >& b){
    vector < T > ans;
    int i = 0, j = 0;
    while (i < sz(a) && j < sz(b)){
      if (a[i] < b[j]) ans.push_back(a[i++]);
      else ans.push_back(b[j++]);
    }
    while (i < sz(a)) ans.push_back(a[i++]);
    while (j < sz(b)) ans.push_back(b[j++]);
    return ans;
  }

  // build the tree
  void build(int node, int start, int end, vector < T >& v){
    if (start == end){
      Tree[node].push_back(v[start]);
      return;
    }
    int mid = (start + end) >> 1;
    build(node << 1, start, mid, v);
    build(node << 1 | 1, mid + 1, end, v);
    Tree[node] = merge(Tree[node << 1], Tree[node << 1 | 1]);
  }

  // return the number of elements greater than k in range [l, r]
  int query(int node, int start, int end, int l, int r, int k){
    if (start > r || end < l) return 0;
    if (start >= l && end <= r){
      int idx = upper_bound(all(Tree[node]), k) - Tree[node].begin();
      return sz(Tree[node]) - idx;
    }
    int mid = (start + end) >> 1;
    return query(node << 1, start, mid, l, r, k) + query(node << 1 | 1, mid + 1, end, l, r, k);
  }

  // constructor
  Merge_sort_Tree(vector < T >& v){
    size = sz(v);
    Tree = vector < vector < T > > (size * 4);
    build(1, 0, size - 1, v);
  }
 
  // query on the tree
  int query(int l, int r, int k){
    return query(1, 0, size - 1, l, r, k);
  }

};

void Accepted(){  

  ll n;
  cin >> n;
  vector < ll > vec(n);
  cin >> vec;
  Merge_sort_Tree < ll > Tree(vec);

  int q;
  cin >> q;
  while (q--){
    int l, r, k;
    cin >> l >> r >> k;
    cout << Tree.query(l - 1, r - 1, k) << "\n";
  }

}

int main(){ 
  
  int tt = 1;
  // cin >> tt;
  Gerges_Hany();
  while(tt--) {
    Accepted();
  }
  Time;
  return 0;
}
