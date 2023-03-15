#include <bits/stdc++.h>
using namespace std; 
#define sz(s) int(s.size())  
typedef long long ll;

template < typename T = int > struct monotonic_stack{
  
  T n;
  vector < T > v;
  vector < T > ans;
  vector < pair < T, T > > st;

  monotonic_stack(vector < T > &v) : v(v) {
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


};

int main()
{

  vector < ll > v = {1, 3, 2, 4, 1};
  monotonic stack < ll > st(v);
  vector < ll > ans = st.next_greater_element();
  for (auto & i: ans) cout << i << " ";

    
  return 0;
}
