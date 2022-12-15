#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

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

