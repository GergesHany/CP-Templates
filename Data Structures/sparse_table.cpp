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

template < class T >  struct sparse_table{

  int LOG;
  vector < int > log_table;
  function < T(T, T) > func;
  vector < vector < T > > table;

  sparse_table(vector < T > &vec, function < T(T, T) > f) : func(f){
    int n = vec.size();
    LOG = 32 - __builtin_clz(n);
    log_table = vector < int > (n + 1);
    table = vector < vector < T > > (LOG + 1, vector < T > (n));
    for(int i = 2; i <= n; i++) log_table[i] = log_table[i >> 1] + 1;

    for(int i = 0; i < n; i++) table[0][i] = vec[i];

    for(int j = 1; j <= LOG; j++){
      for(int i = 0; i + (1 << j) <= n; i++){
        table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T query(int l, int r){
    int j = log_table[r - l + 1];
    return func(table[j][l], table[j][r - (1 << j) + 1]);
  }

  // sparse_table < int > st(vec, [&](int a, int b){ return min(a, b); });

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