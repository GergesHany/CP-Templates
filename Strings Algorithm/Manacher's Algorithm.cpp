#include <bits/stdc++.h>
 
using namespace std; 
#define PI acos(-1)
#define sz(s) (int)(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define ceill(x, y)  ((x + y - 1) / y)
#define all(vec)  vec.begin(), vec.end()
#define Time cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
 
int tt, tc;
typedef long long ll;
typedef long double ld;
const ll INF = 1LL << 60;
const int mod = 1e9 + 7, N = 1e6 + 5;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}

// Palindrome Manacher's Algorithm (get longest palindrome substring)
string palindrome(string& s){
  
  string str = "@#";
  for (char& c : s)str += c, str += '#';
  str += '$';
  
  int strLen = 2 * sz(s) + 3, maxLen = 0;
  int start = 0, maxRight = 0, center = 0;
 
  vector < int > p(strLen); // p[i] = length of palindrome centered at i
  for(int i = 1; i < strLen - 1; i++){
    if (i < maxRight)
        p[i] = min(maxRight - i, p[2 * center - i]); // mirror of i about center
    while (str[i + p[i] + 1] == str[i - p[i] - 1]) p[i]++; // expand palindrome centered at i
    if (i + p[i] > maxRight)
        center = i, maxRight = i + p[i];
    if (p[i] > maxLen)
        start = (i - p[i] - 1) / 2, maxLen = p[i];
  }
 
  return s.substr(start, maxLen);
}

void Accepted(){
  
  
 
} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
  }

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}