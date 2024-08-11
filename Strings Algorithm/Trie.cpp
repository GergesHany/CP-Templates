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

enum class TrieMode { Lowercase, Uppercase, Digits }; // from 7oskaa's Trie
template < TrieMode Mode = TrieMode::Lowercase > class Trie{
public:

  Trie() : root(new Node()) {}
 
  inline const void insert(const string& s) {
    add(s);
  }

  inline const void erase(const string& s){
    remove(s, 0, root);
  }

  inline const bool search(const string& s){
    return find(s);
  }

  inline const bool is_prefix(const string& s){
    return prefix(s);
  }

  ~Trie(){
    function < void(Node*) > dfs = [&](Node* cur){
      if (!cur) return;
      for (int i = 0; i < get_size(); ++i) dfs(cur -> child[i]);
      delete cur;
    };
    dfs(root);
  }  
 
private:
  static constexpr int get_size(){ 
    if constexpr (Mode == TrieMode::Digits) return 10;
    if constexpr (Mode == TrieMode::Lowercase) return 26;
    if constexpr (Mode == TrieMode::Uppercase) return 26;
    assert(false); // unreachable
  }
  
  inline constexpr int get_index(char c){
    if constexpr (Mode == TrieMode::Digits) return c - '0';
    if constexpr (Mode == TrieMode::Lowercase) return c - 'a';
    if constexpr (Mode == TrieMode::Uppercase) return c - 'A';
    assert(false); // unreachable
  }

  struct Node {
    int freq = 0;
    bool is_word = false;
    Node* child[get_size()] = {nullptr};
  };

  Node* root;

  inline void add(const string& s){
    Node* cur = root;
    for (char c : s) {
      int index = get_index(c);
      if (!cur -> child[index]) cur -> child[index] = new Node();
      cur = cur -> child[index];
    }
    cur -> is_word = true;
  }

  inline bool find(const string& s){
    const Node* cur = root;
    for (char c : s) {
      int index = get_index(c);
      if (!cur->child[index]) return false;
      cur = cur->child[index];
    }
    return cur->is_word;
  }

  inline bool prefix(const string& s){
    const Node* cur = root;
    for (char c : s) {
      int index = get_index(c);
      if (!cur->child[index]) return false;
      cur = cur->child[index];
    }
    return true;
  }

  void remove(const string& s, int i, const Node* cur){
    if (i == sz(s)) return void(cur -> is_word = false);
    int index = get_index(s[i]);
    assert(cur -> child[index]); // check if the character exists
    remove(s, i + 1, cur -> child[index]);
    if (cur->child[index] -> freq == 0) {
      delete cur->child[index];
      cur->child[index] = nullptr;
    }
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
