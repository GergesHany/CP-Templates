#include <bits/stdc++.h>
using namespace std; 

#define sz(s) int(s.size())  
typedef long long ll;


template < typename T = int > struct KMP{
  
  string s;
  vector < T > pi;
  
  KMP() = default;

  KMP(string s): s(s){
    pi = vector < T > (sz(s));
    for(int i = 1, j = 0; i < sz(s); i++){
      while(j > 0 && s[i] != s[j]) j = pi[j - 1];
      if(s[i] == s[j]) j++;
      pi[i] = j;
    }
  }

  vector < T > match(string t){
    vector < T > ans(sz(t));
    for(int i = 0, j = 0; i < sz(t); i++){
      while(j > 0 && t[i] != s[j]) j = pi[j - 1];
      if(t[i] == s[j]) j++;
      ans[i] = j;
    }
    return ans;
  }
  
  string get_lps(){
    string ans;
    for(int i = 0; i < sz(s); i++){
      if(pi[i] == 0) continue;
      if(pi[i] == pi[pi[i] - 1]) continue;
      ans += s[i];
    }
    return ans;
  }

};


int main()
{

  string s; cin >> s;
  KMP < ll > kmp(s);  
  vector < ll > ans = kmp.match(s);
  string lps = kmp.get_lps();

  return 0;
}