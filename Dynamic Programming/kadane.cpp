#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

template < typename T = int > struct kadane{

  // max subarray sum in O(n) 1d kadane's algorithm
  T get_max_sum(vector < T >& vec){
      T curr = 0, max_sum = -INF;
      for(auto x : vec){
          curr += x;
          updmax(max_sum, curr);
          curr = max(curr, 0LL);
      }
    return max(max_sum, 0LL);  
  }


  // min subarray sum in O(n) 1d kadane's algorithm  
  T get_min_sum(vector < T >& vec){
    T curr = 0, min_sum = INF;
    for (auto& i: vec) {
      curr += i;
      min_sum = min(min_sum, curr);
      curr = min(curr, 0LL);
    }
    return min(min_sum, 0LL);
  }

  // max subarray sum 2d kadane's algorithm
  T get_max_sum(vector < vector < T > >& vec){
    T n = sz(vec), m = sz(vec[0]);
    T max_sum = -INF;
    for(int i = 0; i < m; i++){
      vector < T > temp(n);
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++) temp[k] += vec[k][j];
        updmax(max_sum, get_max_sum(temp));
      }
    }
    return max(max_sum, 0LL);
  }


  // min subarray sum 2d kadane's algorithm
  T get_min_sum(vector < vector < T > >& vec){
    T n = sz(vec), m = sz(vec[0]);
    T min_sum = INF;
    for(int i = 0; i < m; i++){
      vector < T > temp(n);
      for(int j = i; j < m; j++){
        for(int k = 0; k < n; k++) temp[k] += vec[k][j];
        updmin(min_sum, get_min_sum(temp));
      }
    }
    return min(min_sum, 0LL);
  }

};

