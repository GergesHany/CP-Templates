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
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>
  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 3000 + 5;
  
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

struct Item {

  ll val;

  Item(ll val = 0) : val(val) {}  
  Item operator = (const ll rhs) {
    val = rhs;
    return *this;
  }

};

template < typename T = int , bool Base = 0 > struct Segment_Tree {

  T size; 
  Item DEFAULT;
  vector < Item > Tree; 
  function < Item(const Item&, const Item&) > op;
  
   Segment_Tree(T n, const vector < T >& vec, T Default, function<Item(const Item&, const Item&)> f) : op(f){
    size = 1;
    DEFAULT = Item(Default);
    while(size < n) size <<= 1;
    Tree = vector < Item > (size << 1, DEFAULT);
    build(vec);
  }
  
  void build(const vector < T >& vec, int idx, int L, int R){
    if ((Base && L >= sz(vec)) || (!Base && L > sz(vec))) return;
    if(R == L) return void(Tree[idx] = vec[L - !Base]);
    int mid = (R + L) / 2;
    build(vec, idx << 1 , L, mid);
    build(vec, idx << 1 | 1, mid + 1, R);
    Tree[idx] = op(Tree[idx << 1], Tree[idx << 1 | 1]);
  }

  void build(const vector < T >& vec){
    build(vec, 1, 1, size);
  }

  void update(int index, T value, int idx, int L, int R){
    if(R == L) return void(Tree[idx] = value);
    int mid = (R + L) / 2;
    if(index <= mid) update(index, value, idx << 1, L, mid);
    else update(index, value, idx << 1 | 1, mid + 1, R);
    Tree[idx] = op(Tree[idx << 1], Tree[idx << 1 | 1]);
  }

  void update(const int index, const T value){
    update(index, value, 1, 1, size);
  }
 
  Item query(int L, int R, int idx, int lq, int rq){
    if(lq > R || L > rq) return DEFAULT;
    if(lq >= L && rq <= R) return Tree[idx];
    int mid = (lq + rq) / 2;
    return op(query(L, R, idx << 1, lq, mid), query(L, R, idx << 1 | 1, mid + 1, rq));
  }
 
  T query(const int l, const int r){
    return query(l, r, 1, 1, size).val;
  }

  /*    
    function < Item(const Item&, const Item&) > f = [&](Item a, Item b) -> Item {
      return a.val < b.val ? a : b;
    };
    Segment_Tree < ll, 0 > st(n, a, INF, f);
  */

};

void Accepted(){
  
}

int main()
{ 

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){
    // cout << "Case " << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}
