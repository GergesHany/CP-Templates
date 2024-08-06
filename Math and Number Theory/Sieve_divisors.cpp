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

vector < int > prime;
bool is_composite[N];
int prime_div[N], ex[N], divs[N];
 
// ex[i] is the power of the prime_div[i] in the prime factorization of i 
// divs[i] is the number of divisors of i
// prime_div[i] is the smallest prime dividing i
 
void init() { // O(N * log(log(N)))
  divs[1] = 1, ex[1] = 0;
  for (int i = 2; i < N; ++i) {
    if (!is_composite[i]) {
      prime.push_back(i);
      prime_div[i] = i;
      ex[i] = 1;
      divs[i] = 2;
    }
 
    for (int j = 0; j < sz(prime) && i * prime[j] < N; ++j) {
      is_composite[i * prime[j]] = true;
      if (i % prime[j] == 0) {
        prime_div[i * prime[j]] = prime[j] * prime_div[i];
        ex[i * prime[j]] = ex[i] + 1;
        divs[i * prime[j]] = divs[i / prime_div[i]] * (ex[i * prime[j]] + 1);
        break;
      } else {
        prime_div[i * prime[j]] = prime[j];
        ex[i * prime[j]] = 1;
        divs[i * prime[j]] = divs[i] * 2;
      }
    }
  }
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
