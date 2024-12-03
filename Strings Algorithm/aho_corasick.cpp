#include <algorithm>
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

class aho_corasick_node {

private:
  struct node {
    vector < int > occ;
    int child[26], cnt, link;
    node() : cnt(0), link(-1) { 
      memset(child, -1, sizeof child); 
    }
  };
  vector < node > tree;

public:

  aho_corasick_node() = default;

  aho_corasick_node(const vector < pair < string, int > >& patterns) {
    tree = vector < node > (1);
    for (auto [s, idx] : patterns) {
      int cur = 0;
      for (char c : s) {
        int to = c - 'a';
        if (tree[cur].child[to] == -1) {
          tree[cur].child[to] = sz(tree);
          tree.emplace_back(node());
        }
        cur = tree[cur].child[to];
      }
      tree[cur].cnt++;
      tree[cur].occ.push_back(idx);
    }

    build_links(); // build the links of the trie
  }
  
  inline void build_links(){
    queue < int > q;
    q.push(0);
    
    while(sz(q)){
      int node = q.front();
      q.pop();

      for (int i = 0; i < 26; i++) {
        int v = tree[node].child[i];
        if (~v){
          int j = tree[node].link;
          while(~j and !~tree[j].child[i]) j = tree[j].link;
          
          tree[v].link = (~j ? tree[j].child[i] : 0);
          tree[v].cnt += tree[tree[v].link].cnt;
          tree[v].occ.insert(tree[v].occ.end(), all(tree[tree[v].link].occ));

          q.push(v);
        }
      }

    }
  }

  // count the occurrences of the patterns in the string
  ll count_occurrences(const string &s){
    ll ans = 0, cur = 0;
    for (char c : s) {
      int to = c - 'a';
      while (~cur and !~tree[cur].child[to]) cur = tree[cur].link;
      cur = (~cur ? tree[cur].child[to] : 0);
      ans += tree[cur].cnt;
    }
    return ans;
  }
  
  // get the indices of the patterns in the string
  inline void get_occ(const string& s, vector < vector < int > >& ret){
    int cur = 0;
    for (int i = 0; i < sz(s); i++) {
      int to = s[i] - 'a';
      while (~cur and !~tree[cur].child[to]) cur = tree[cur].link;
      cur = (~cur ? tree[cur].child[to] : 0);
      for (int idx : tree[cur].occ) ret[idx].push_back(i);
    }
  } 

};

class aho_corasick {

private:  

  int curr_size = 0;
  static const int LOG = 20;
  aho_corasick_node aho[LOG];
  vector < pair < string, int > > list[LOG];
  
public:
  
  inline int get_nxt(){
    for (int i = 0; i < LOG; i++) 
      if (list[i].empty())
        return i;
    return 0; // root
  }
  
  inline void insert(const string& s){
    int idx = get_nxt();
    
    for (int bef = 0; bef < idx; bef++) {
      for (auto & it : list[bef]) {
        list[idx].push_back(it);
      }
      list[bef].clear();
      aho[bef] = aho_corasick_node();
    }

    list[idx].emplace_back(s, curr_size++);
    aho[idx] = aho_corasick_node(list[idx]);
  }

  inline ll count(const string &s){
    ll ans = 0;
    for (int i = 0; i < LOG; i++) 
      if (!list[i].empty()) ans += aho[i].count_occurrences(s);
    return ans;
  }

  vector < vector < int > > get_occ(const string& s){
    vector < vector < int > > ans(curr_size);
    for (int i = 0; i < LOG; i++) {
      if (!list[i].empty()) aho[i].get_occ(s, ans);
    }
    return ans;
  }

  inline void delete_word(const string& s) {
    for (int l = 0; l < LOG; l++) {
      auto it = find_if(all(list[l]), [&](const pair<string, int>& p) { return p.first == s; });
      if (it != list[l].end()) {
        list[l].erase(it);
        aho[l] = aho_corasick_node(list[l]);
        break;
      }
    }
  }


};

void Accepted(){

  int q;
  cin >> q;

  aho_corasick ac;

  while (q--) {
    int t;
    string s;
    cin >> t >> s;
    if (t == 1) {
      ac.insert(s);
    } else if (t == 2) {
      ac.delete_word(s);
    } else {
      cout << ac.count(s) << '\n';
    }
  }  
 
} 

signed main(){ 

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  tt = tc = 1; // cin >> tt;
  while (tt--) Accepted(), ++tc;  

  Time;
  return 0;
}
