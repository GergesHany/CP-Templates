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

template <typename T = int, const int N = 1e6 > class MEX {
public:
  
  MEX() {};
  bitset < N > mex; 
  vector < int > cnt;

  inline void init() {
    cnt.assign(N, 0);
    for (int i = 0; i < N; i++) mex[i] = true; // all numbers are mex initially
  }

  inline void add(const T x) {
    insert(x);
  }

  inline void remove(const T x) {
    erase(x);
  }

  inline int get_mex() {  
    return calculate_mex();
  }
 
private:
  inline void insert(const T x) {
    if (x >= N) return;
    if (++cnt[x] == 1) mex[x] = false;  
  }
  
  inline void erase(const T x) {
    if (x >= N) return;
    if (--cnt[x] == 0) mex[x] = true;  
  }
  
  const inline int calculate_mex() {
    return mex._Find_first();  
  }
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
