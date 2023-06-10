
template < int LOG = 0 > struct Trie{
  
  char base_char[4] = {'a', 'A', '0', '0'};
  constexpr static int sz[4] = {26, 26, 10, 2}; 
  
  struct node{
  
    int freq;
    bool isval;
    node* child[sz[3]];
    
    node(){
      freq = 0;
      isval = false;
      memset(child, 0, sizeof(child));
    }
  }; 
 
  node* root;
 
  Trie(){
    root = new node;
  }
 
  void insert(int val){
    node* current = root;
    for(int bit = LOG; bit >= 0; bit--){
       ll bit_val = (val >> bit) & 1;
        if (current -> child[bit_val] == nullptr) 
          current -> child[bit_val] = new node;
        current = current -> child[bit_val];
      current -> freq++;
    }
  }
 
  void erase(const ll val, int bit, node* curr){
    if (bit == -1) return void(curr -> isval = curr -> freq > 1);
    ll bit_val = (val >> bit) & 1;
    erase(val, bit - 1, curr -> child[bit_val]);
    if (--curr -> child[bit_val] -> freq == 0){
      delete curr -> child[bit_val];
      curr -> child[bit_val] = nullptr;
    }
  }

  bool search(ll val){
    node* current = root;
    for(int bit = LOG; bit >= 0; bit--){
      ll bit_val = (val >> bit) & 1;
      if (current -> child[bit_val] == nullptr) return false;
      current = current -> child[bit_val];
    }
    return current -> isval;
  }

  void erase(ll val){
     erase(val, LOG, root);
  }
 
  ll max_xor(ll val){
    ll ans = 0;
    node* current = root;
    for(int bit = LOG; bit >= 0; bit--){
      ll bit_val = (val >> bit) & 1;
      if (current -> child[bit_val ^ 1] != nullptr){
        ans += (1LL << bit);
        current = current -> child[bit_val ^ 1];
      }
      else current = current -> child[bit_val];
    }
    return ans;
  }
 
};
