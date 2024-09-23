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

template < typename T = int > class Binary_Trie{
public:
 
  Binary_Trie(int log = 31) : root(new Node()), LOG(log) {}
 
  inline bool get_bit(const T x, const int bit) const {
    return (x >> bit) & 1;
  }
 
  inline void insert(const T x) {
    add(x);
  }
 
  inline void erase(const T x) {
    assert(search(x)); // element must be present in the trie
    erase(x, LOG, root);
  }
 
  inline bool search(const T x) {
    return find(x);
  }
 
  inline T max_xor(const T x) {
    return get_max_xor(x);
  }
 
  inline T min_xor(const T x) {
    return ((1LL << LOG) - 1) ^ get_max_xor(x ^ ((1LL << LOG) - 1));
  }
 
  inline T count(const T x, const T k) {
    return count_less_equal(x, k);
  }
  
  inline T count_greater(const T x, const T k) {
    return cnt - count_less_equal(x, k);
  }
 
  #ifdef LOCAL
  ~Binary_Trie(){
    function < void(Node*) > dfs = [&](Node* cur){
      if (!cur) return;
      for (int i = 0; i < 2; ++i) dfs(cur -> child[i]);
      delete cur;
    };
    dfs(root);
  }
  #endif
 
private:
  
  struct Node {
    int freq;
    Node* child[2];
    Node() : freq(0), child{nullptr, nullptr} {}
  };
 
  Node* root;
  int LOG, cnt;
 
  inline void add(const T x){
    ++cnt; // inc number of elements in the trie
    Node* cur = root;
    for(int i = LOG; ~i; i--){
      bool bit = get_bit(x, i);
      if(!cur -> child[bit]) 
          cur -> child[bit] = new Node();
      cur = cur -> child[bit];
      cur -> freq++;
    }
  }
 
  void erase(const T x, const int bit, Node* curr) {
    if(bit < 0) return void(--cnt);
    bool bit_val = get_bit(x, bit);
    erase(x, bit - 1, curr -> child[bit_val]);
    if (--curr -> child[bit_val] -> freq == 0) {
      delete curr -> child[bit_val];
      curr -> child[bit_val] = nullptr;
    }
  }
 
  inline bool find(const T x){
    Node* cur = root;
    for(int i = LOG; ~i; i--){
      bool bit = get_bit(x, i);
      if(!cur -> child[bit] or !cur -> child[bit] -> freq) 
          return false;
      cur = cur -> child[bit];
    }
    return true;
  }
 
  inline T get_max_xor(const T x){
    T ans = 0;
    Node* cur = root;
    for(int i = LOG; ~i; i--){
      bool bit = get_bit(x, i);
      if(cur -> child[!bit] and cur -> child[!bit] -> freq){
        ans |= (1LL << i);
        cur = cur -> child[!bit];
      }else cur = cur -> child[bit];
    }
    return ans;
  }
 
  // number of pairs such that (p ^ val) <= k
  inline T count_less_equal(const T x, const T k){
    T ans = 0;
    Node* cur = root;
    for(int i = LOG; ~i; i--){
      if(!cur) break;
      bool val_bit = get_bit(x, i), k_bit = get_bit(k, i);
      if(k_bit){
        if(cur -> child[val_bit]) 
            ans += cur -> child[val_bit] -> freq;
        cur = cur -> child[val_bit ^ 1];
      }else cur = cur -> child[val_bit];
    }
    if(cur) ans += cur -> freq;
    return ans;
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
