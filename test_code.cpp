#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;

#define EPS 1e-18
#define sz(s) int(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define TC int t; cin >> t; while(t--)
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define updmin(a, b) a = min((ll)a, (ll)b)
#define updmax(a, b) a = max((ll)a, (ll)b)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define watch(x) cout << (#x)<<" = "<<x<< "\n"
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define cin_2d(vec, n, m) for(int i=0;i<n;i++) for(int j=0;j<m&&cin>>vec[i][j];j++);
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>

typedef long long ll;
const ll N = 2 * 1e5 + 5;
typedef long double ld;
typedef unsigned long long ull;
const ll Mod = 1'000'000'007;
const ll INF = 2'000'000'000;
const double PI = acos(-1.0);
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}
 
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

/*

 * don't be lazy in thinking 
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down
 * Think of different views of the problem. don't look from only one side

*/


struct kadane{

  // max subarray sum in O(n) 1d kadane's algorithm
  ll get_max_sum(vector < ll >& vec){
      ll curr = 0, max_sum = -INF;
      for(auto x : vec){
          curr += x;
          updmax(max_sum, curr);
          curr = max(curr, 0LL);
      }
    return max(max_sum, 0LL);  
  }


  // min subarray sum in O(n) 1d kadane's algorithm  
  ll get_min_sum(vector < ll >& vec){
    ll curr = 0, min_sum = INF;
    for (auto& i: vec) {
      curr += i;
      min_sum = min(min_sum, curr);
      curr = min(curr, 0LL);
    }
    return min(min_sum, 0LL);
  }

  // max subarray sum 2d kadane's algorithm
  ll get_max_sum(vector < vector < ll > >& vec){
    ll n = sz(vec), m = sz(vec[0]);
    ll max_sum = -INF;
    for(int i = 0; i < m; i++){
      vector < ll > temp(n);
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++) temp[k] += vec[k][j];
        updmax(max_sum, get_max_sum(temp));
      }
    }
    return max(max_sum, 0LL);
  }


  // min subarray sum 2d kadane's algorithm
  ll get_min_sum(vector < vector < ll > >& vec){
    ll n = sz(vec), m = sz(vec[0]);
    ll min_sum = INF;
    for(int i = 0; i < m; i++){
      vector < ll > temp(n);
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++) temp[k] += vec[k][j];
        updmin(min_sum, get_min_sum(temp));
      }
    }
    return min(min_sum, 0LL);
  }

};


void Accepted(){
 


} 

int main()
{

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){  
    // cout << "Case #" << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}

