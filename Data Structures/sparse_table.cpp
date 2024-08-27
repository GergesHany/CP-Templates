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


template < typename Tabletype = int, typename numsType = int > class Sparse_Table{
 
private:
  using T = Tabletype;
 
  int LOG;
  Tabletype DEFAULT;
  function < T(T, T) > func;
  vector < numsType > log_table;
  vector < vector < T > > table;
 
  inline void Build_Table(const vector < numsType > &vec){
   for(int i = 0; i < sz(vec); i++) table[0][i] = vec[i];
    for(int j = 1; j <= LOG; j++){
      for(int i = 0; i + (1 << j) <= sz(vec); i++){
        table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
 
  inline void init(const int n){
    LOG = 32 - __builtin_clz(n);
    log_table = vector < numsType > (n + 1);
    for(int i = 2; i <= n; i++) log_table[i] = log_table[i >> 1] + 1;
    table = vector < vector < T > > (LOG + 1, vector < T > (n, DEFAULT));
  }
 
  // O(1) query (not overlapping)
  const inline T query_1(int l, int r){
    int j = log_table[r - l + 1];
    return func(table[j][l], table[j][r - (1 << j) + 1]);
  }
 
  // O(logn) query (overlapping)
  const inline T query_2(int l, int r){
    T ans = DEFAULT;
    for(int j = LOG; j >= 0; j--){
      if((1 << j) <= r - l + 1)
        ans = func(ans, table[j][l]), l += 1 << j;
    }
    return ans;
  }
 
public:
 
  const inline T query(int l, int r, bool is_overlap = false){
    return (!is_overlap ? query_1(l, r) : query_2(l, r));
  }
 
  Sparse_Table(const vector < numsType > &vec, T def, function < T(T, T) > f) : DEFAULT(def), func(f) {
    init(sz(vec));
    Build_Table(vec);
  }
 
  // Sparse_Table < ll, ll > mn(a, 1e18, [&](ll a, ll b){ return min(a, b); });
 
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
