#include <bits/stdc++.h>
using namespace std; 
#define sz(s) int(s.size())  
typedef long long ll;

template < typename T = int > struct monotonic_stack{
  
  T n;
  vector < T > v;
  vector < T > ans;
  stack < pair < T, T > > st;
 
  monotonic_stack(vector < T > &v) : v(v) {
    n = sz(v);
    ans = vector < T > (n);
  }
  
  // function to get the next greater if no greater element return -1
  vector < T > next_greater_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.top().first <= v[i]) st.pop();
      ans[i] = (st.empty() ? -1 : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // function to get the previous greater if no greater element return -1
  vector < T > prev_greater_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.top().first <= v[i]) st.pop();
      ans[i] = (st.empty() ? n : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // function to get the next smaller if no smaller element return n
  vector < T > next_smaller_element(){
    for(int i = n - 1; i >= 0; i--){
      while(!st.empty() && st.top().first >= v[i]) st.pop();
      ans[i] = (st.empty() ? n : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
  // funtion to get the previous smaller if no smaller element return -1
  vector < T > prev_smaller_element(){
    for(int i = 0; i < n; i++){
      while(!st.empty() && st.top().first >= v[i]) st.pop();
      ans[i] = (st.empty() ? -1 : st.top().second);
      st.push({v[i], i});
    }
    return ans;
  }
 
 
};

int main()
{

    
  return 0;
}
