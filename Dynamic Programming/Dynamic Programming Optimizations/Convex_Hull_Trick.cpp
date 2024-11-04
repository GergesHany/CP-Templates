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


// line container
struct Line {

  mutable ll m, c, p;

  // compare two lines by slope
  bool operator < (const Line &o) const { return m < o.m; }

  // check if line x is irrelevant
  bool operator < (ll x) const { return p < x; }

  // get the value of the line at x: 
  ll val(ll x) const { return m * x + c; }

};

// Convex Hull Trick
// line equation is y = mx + c
// Mode = 1 for maximum, Mode = -1 for minimum
template < typename T = int, T Mode = -1 > class CHT : multiset < Line, less < > > {

private:  
  static constexpr T LLimit = numeric_limits < T > :: min();
  static constexpr T RLimit = numeric_limits < T > :: max();

  const T div(T a, T b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }

  // check if line x is irrelevant
  bool is_intersect(iterator x, iterator y) {
    if (y == end()) return x -> p = RLimit, 0;
    if (x -> m == y -> m) x -> p = (x -> c > y -> c ? RLimit : LLimit);
    else x -> p = div(y -> c - x -> c, x -> m - y -> m);
    return x -> p >= y -> p;
  }
  
  // insert line y = mx + c
  const inline void add(T m, T c) {
    m *= Mode, c *= Mode;
    auto z = insert({m, c, 0}), y = z++, x = y;
    while (is_intersect(y, z)) z = erase(z); // remove irrelevant lines
    if (x != begin() && is_intersect(--x, y)) is_intersect(x, y = erase(y));

    // update intersection point
    while ((y = x) != begin() && (--x) -> p >= y -> p) is_intersect(x, erase(y)); 
  }

  // get the value of the line
  const inline T get(const T x) {
    assert(!empty());
    auto l = *lower_bound(x); // get the line with the smallest slope
    return Mode * l.val(x);
  }

  // get the number of lines in the container
  const inline T get_size() {
    return multiset < Line, less < > > :: size();
  }

public:
  
  const inline void insert_line(T m, T c) {
    add(m, c);
  }

  const inline T query(const T x) {
    return get(x);
  }

  const inline T size(){
    return get_size();
  }

  vector < Line > get_lines() {
    return vector < Line > (begin(), end());
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