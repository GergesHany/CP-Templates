#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
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

template < typename T = int > class MEX{
  
public:
    int n, block_size;
    vector < int > cnt, blocks;
    
    MEX() {};

    inline void init(int N = 0){
        n = N;
        block_size = sqrt(n) + 1;
        cnt = vector < int > (n + 1, 0);
        blocks = vector < int > (block_size, 0);
    }

    inline void add(const T x){
        insert(x);
    }

    inline void remove(const T x){
        erase(x);
    }

    inline int mex(){
        return get_mex();
    }

private:

    inline void insert(const T x){
      if (x > n) return;
      if (++cnt[x] == 1) blocks[x / block_size]++;
    }
    
    inline void erase(const T x){
       if (x > n) return;
       if (--cnt[x] == 0) blocks[x / block_size]--;
    }
    
    const inline int get_mex(){
        for (int i = 0; i < block_size; i++) if (blocks[i] < block_size) {
            for (int j = i * block_size; j < min(n, (i + 1) * block_size); j++) 
              if (!cnt[j]) return j;
        }
        return n + 1;
    }

};


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
