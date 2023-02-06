template < int base = 0 > struct Trie{
  
  char base_char[4] = {'a', 'A', '0', '0'};
  constexpr static int sz[4] = {26, 26, 10, 2}; 

  struct node{
  
    int freq;
    bool isWord;
    node* child[sz[base]];
    
    node(){
      freq = 0;
      isWord = false;
      memset(child, 0, sizeof(child));
    }
  }; 

  node* root;

  Trie(){
    root = new node();
  }

  void insert(string s){
    node* current = root;
    for(auto c : s){
      int idx = c - base_char[base];
      if (current -> child[idx] == NULL) 
        current -> child[idx] = new node;
      current = current -> child[idx];
      current -> freq++;
    }
    current -> isWord = true;
  }

  bool search(string s){
    node* current = root;
    for (auto c : s){
      int idx = c - base_char[base];
      if (current -> child[idx] == NULL) return false;
      current = current -> child[idx];
    }
    return current -> isWord;
  }

  bool is_prefix(string s){
    node* current = root;
    for (auto c : s){
      int idx = c - base_char[base];
      if (current -> child[idx] == NULL) return false;
      current = current -> child[idx];
    }
    return true;
  }

  void erase(const string& word, int idx, node* current){
    if(idx == sz(word)) return void(current -> isWord = current -> freq != 1);
    erase(word, idx + 1, current -> child[word[idx] - base_char[base]]);
    if(--current -> child[word[idx] - base_char[base]] -> freq == 0){
        delete current -> child[word[idx] - base_char[base]];
        current -> child[word[idx] - base_char[base]] = nullptr;
    }
  }
  
  void erase(string s){
    if (search(s))
     erase(s, 0, root);
  }

};
