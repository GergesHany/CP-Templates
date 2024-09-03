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

template < typename T = int > struct Xor_basis {
  
  vector < T > basis;
 
  Xor_basis() = default;
 
  Xor_basis(T x) {
    basis = {x};
  }
 
  // reduce x to its simplest form
  T reduce(T x) {
    for (T &b : basis) x = min(x, x ^ b);
    return x;
  }
 
  bool add(T x) {
    x = reduce(x); 
    if (x == 0) return false;
    return basis.push_back(x), true;
  }
 
  // check if can represent x as a linear combination of the basis
  bool check(T x) {
    return reduce(x) == 0;
  }
 
  // merge two basis
  Xor_basis operator + (const Xor_basis &other) const {
    Xor_basis res = *this;
    for (T x : other.basis) res.add(x);
    return res;
  }
 
  // get maximum value that can be represented by the basis
  T max_xor() {
    T res = 0;
    for (T x : basis) res = max(res, res ^ x);
    return res;
  }
 
  // apply a function to all elements of the basis
  void applay(function < T(T, T) > f, T x = 0){
    vector < T > new_basis;
    for (T y : basis) new_basis.push_back(f(x, y));
    basis.clear();
    for (T y : new_basis) add(y);
  }
 
};

void Accepted(){
  
  
 
} 

int main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}