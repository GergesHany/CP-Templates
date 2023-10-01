#include <bits/stdc++.h>

using namespace std; 
#define sz(s) (int)(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define ceill(x, y) ((x + y - 1) / y) 
#define all(vec)  vec.begin(), vec.end()
#define Time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

int tt, tc;
typedef long long ll;
typedef long double ld;
const ll INF = 1LL << 60;
const int mod = 1e9 + 7, N = 5e5 + 5;


ll freq[N];
template < typename T = int, bool Base = 0 > struct MO{

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
    int l, r, idx;

    Query(int L = 0, int R = 0, int Idx = 0) : l(L - !Base), r(R - !Base), idx(Idx) {
      calcOrder();
    }

    inline void calcOrder() {
        ord = hilbertOrder(l, r, 20, 0); // 20 should be minimum such that 2^20 >= n
    }

    bool operator < (const Query & rhs) const{
        return ord < rhs.ord;
    }
  };

  vector < T > arr, ans;
  vector < Query > queries;
  T n, q, block_size, cur_l, cur_r, cur_ans;
  
  MO(T N, T Q){
    n = N, q = Q, block_size = q / sqrt(n) + 1, cur_ans = 0;
    queries = vector < Query > (q), ans = vector < T > (q);
  }

  void Scan(vector < T >& a){
    arr = a;
    for (int i = 0, L, R; i < q && cin >> L >> R; i++) queries[i] = Query(L, R, i);
    sort(all(queries));
  }

  inline void add(int idx){
    if (++freq[arr[idx]] == 1) cur_ans++;
  }

  inline void remove(int idx){
    if (--freq[arr[idx]] == 0) cur_ans--;
  }

  inline void move(int l, int r){
    while (cur_l > l) add(--cur_l);
    while (cur_r < r) add(++cur_r);
    while (cur_l < l) remove(cur_l++);
    while (cur_r > r) remove(cur_r--);
  }

  inline void solve(){
    cur_l = queries[0].l, cur_r = queries[0].l - 1;
    for (int i = 0; i < q; i++){
      move(queries[i].l, queries[i].r);
      ans[queries[i].idx] = cur_ans;
    }
  }
  
  vector < T > getAns(){
    return ans;
  }

};

void Accepted(){

  ll n, q;
  cin >> n >> q;
  vector < ll > a(n);
  for (auto &i : a) cin >> i;
  MO < ll > mo(n, q);
  mo.Scan(a);
  mo.solve();
  auto ans = mo.getAns();
  for (auto &i : ans) cout << i << '\n';

} 

int main(){ 


  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), tc++;
  
  Time;
  return 0;
}