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
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 2e6 + 5;
  
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


template < typename T = int > struct coordinate_compression{

  vector < T > compressed, nums;

  coordinate_compression(const vector < T >& v){
    nums = v;
    for (auto & i: v) add(i);
    compress();
  }

  void add(T x){
    compressed.push_back(x);
  }

  void compress(){
    sort(all(compressed));
    compressed.erase(unique(all(compressed)), compressed.end());
  }

  T Get(T x){
    return lower_bound(all(compressed), x) - compressed.begin() + 1;
  }

  vector < T > Get_maping(){
    for (auto & x: nums) x = Get(x);
    return nums; 
  }

};

void Accepted(){  

  int n;
  cin >> n;
  vector < int > vec(n);
  cin >> vec;
  coordinate_compression < int > cc(vec);
  vector < int > ans = cc.Get_maping();
  cout << vec << '\n' << ans << '\n';

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
