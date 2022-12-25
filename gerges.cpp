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
const ll Mod = 1000000007;
const ll INF = 1LL << 60;
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

template < typename T = int > struct montonic_stack{
  
  T n;
  vector < T > v;
  vector < T > ans;
  vector < pair < T, T > > st;

  montonic_stack(vector < T > &v) : v(v) {
    n = sz(v);
    ans = vector < T > (n);
  }
  
  // function to get the next greater if no greater element return -1
  vector < T > next_greater_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.back().first <= v[i]) st.pop_back();
      ans[i] = (st.empty() ? -1 : st.back().second);
      st.push_back({v[i], i});
    }
    return ans;
  }

  // function to get the previous greater if no greater element return -1
  vector < T > prev_greater_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.back().first <= v[i]) st.pop_back();
      ans[i] = (st.empty() ? -1 : st.back().second);
      st.push_back({v[i], i});
    }
    return ans;
  }

  // function to get the next smaller if no smaller element return -1
  vector < T > next_smaller_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.back().first >= v[i]) st.pop_back();
      ans[i] = (st.empty() ? -1 : st.back().second);
      st.push_back({v[i], i});
    }
    return ans;
  }

  // funtion to get the previous smaller if no smaller element return -1
  vector < T > prev_smaller_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.back().first >= v[i]) st.pop_back();
      ans[i] = (st.empty() ? -1 : st.back().second);
      st.push_back({v[i], i});
    }
    return ans;
  }

  // print the answer
  void print(){
    for (int i = 0; i < n; i++) 
      cout << ans[i] << " \n"[i == n - 1];
  }

};

void Accepted(){
 
  vector < ll > v = {1, 3, 2, 4, 1};
  montonic_stack < ll > st(v);
  vector < ll > ans = st.next_greater_element();
  cout << ans;
  
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