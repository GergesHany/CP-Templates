#include <bits/stdc++.h>
using namespace std; 

#define sz(s) int(s.size())  
typedef long long ll;

template < typename T = int > struct KMP{
  
  string s;
  vector < T > pi;
  
  explicit KMP() = default;

  // Prefix Function (failure function)
  explicit KMP(string s): s(s){
    pi = vector < T > (sz(s));
    for(int i = 1, j = 0; i < sz(s); i++){
      while(j > 0 && s[i] != s[j]) j = pi[j - 1]; 
      j += bool(s[i] == s[j]);
      pi[i] = j;
    }
  }

  // Find all occurences of patern in s
  vector < T > find(const string patern){
    vector < T > ans;
    for(int i = 0, j = 0; i < sz(s); i++){
      while(j > 0 && s[i] != patern[j]) j = pi[j - 1];
      if(s[i] == patern[j]) j++;
      if(j == sz(patern)) ans.push_back(i - j + 1), j = pi[j - 1];
    }
    return ans;
  }
  
  // check if s is a repetition of some prefix ex: abcabcabc -> is a repetition of abc
  pair < bool, T > repetition(){
    T len = sz(s) - pi.back();
    if(sz(s) % len == 0) return {true, sz(s) / len};
    return {false, 1};
  }

  // count number of occurrences of each prefix
  vector < T > count_prefix(){
    vector < T > cnt(sz(s) + 1);
    for(int i = 0; i < sz(s); i++) cnt[pi[i]]++;
    for(int i = sz(s) - 1; i > 0; i--) cnt[pi[i - 1]] += cnt[i];
    for(int i = 0; i <= sz(s); i++) cnt[i]++;
    return cnt;
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
