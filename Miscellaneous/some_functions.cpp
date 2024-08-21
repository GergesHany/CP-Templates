#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// Function to find the minimal rotated string using Booth's Algorithm
string min_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}


// Function to find the maximum rotated string using Booth's Algorithm
string max_cyclic_string(string s) {
    s += s;
    int n = s.size();
    int i = 0, ans = 0;
    while (i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while (j < n && s[k] >= s[j]) {
            if (s[k] > s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n / 2);
}
  
  
// Tic-Tac-Toe Game
bool check(char c, vector < vector < char > > &vec){
  // diagonal
  if(vec[0][0] == c && vec[1][1] == c && vec[2][2] == c) return true;
  if(vec[0][2] == c && vec[1][1] == c && vec[2][0] == c) return true;
  // row
  for(int i = 0; i < 3; ++i){
    if(vec[i][0] == c && vec[i][1] == c && vec[i][2] == c) return true;
  }
  // col
  for(int i = 0; i < 3; ++i){
    if(vec[0][i] == c && vec[1][i] == c && vec[2][i] == c) return true;
  }
  return false;
}
  
// function to count the numbers containing 4 in their digits from 1 to n
ll countNumbersWith4(ll n){
  if (n < 4) return 0;
 
  auto fastpow = [&](ll a, ll b){
    ll res = 1;
    while(b){
      if(b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  };

  ll d = log10(n);   
  vector < ll > a(d + 1);
  a[0] = 0, a[1] = 1;
  for (ll i = 2; i <= d; i++)
    a[i] = a[i - 1] * 9 + fastpow(10, i - 1);
 
  ll p = fastpow(10, d);
  
  ll msd = n / p;
  
  if (msd == 4)
    return (msd) * a[d] + (n % p) + 1;
 
  if (msd > 4)
    return (msd - 1) * a[d] + p + countNumbersWith4(n % p);
  
  return msd * a[d] + countNumbersWith4(n % p);
}


// function to find all the sub-strings of a string
vector < string > subString(string s, int n){
   vector < string > vec; 
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n - i; j++)
            vec.push_back( s.substr(i, j) );
    return vec;
}     

