#include <bits/stdc++.h>
 
using namespace std; 
#define PI acos(-1)
// #define int long long
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

struct fraction {

  ll n, d; // numerators and denominators

  fraction() { 
    n = d = 0; 
  }

  fraction(ll a) { 
    n = a, d = 1; 
    this -> simplify();
  }
  
  fraction(ll a, ll b) { 
    n = a, d = b; 
    simplify(); 
  }
  
  fraction operator + (const fraction &f) const {
    return fraction{n * f.d + f.n * d, d * f.d};
  }
  
  fraction operator - (const fraction &f) const {
    return fraction{n * f.d - f.n * d, d * f.d};
  }
  
  fraction operator / (const fraction &f) const {
    return fraction{n * f.d, d * f.n};
  }

  fraction operator * (const fraction &f) const {
    return fraction{n * f.n, d * f.d};
  }

  bool operator == (const fraction &f) const {
    return n == f.n && d == f.d;
  }

  bool operator != (const fraction &f) const {
    return n != f.n || d != f.d;
  }

  bool operator < (const fraction &f) const {
    return n * f.d < f.n * d;
  }

  bool operator > (const fraction &f) const {
    return n * f.d > f.n * d;
  }

  bool operator <= (const fraction &f) const {
    return n * f.d <= f.n * d;
  }

  bool operator >= (const fraction &f) const {
    return n * f.d >= f.n * d;
  }

  // Simplify the fraction
  void simplify() {
    if (d == 0) return; 
    ll g = gcd(n, d); 
    n /= g; 
    d /= g;
    if (d < 0) n = -n, d = -d;
  }
};

void Accepted(){


 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
