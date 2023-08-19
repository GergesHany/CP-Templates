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
  
  string get_lps(){
    string ans;
    for(int i = 0; i < sz(s); i++){
      if(pi[i] == 0) continue;
      if(pi[i] == pi[pi[i] - 1]) continue;
      ans += s[i];
    }
    return ans;
  }

  T count(string s, string patern){
    T ans = 0;
    for(int i = 0, j = 0; i < sz(s); i++){
      while(j > 0 && s[i] != patern[j]) j = pi[j - 1];
      if(s[i] == patern[j]) j++;
      if(j == sz(patern)) ans++, j = pi[j - 1];
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
