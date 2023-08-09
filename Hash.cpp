template < typename T = long long , int Base = 0 > struct Hash {
 
  const T p[2] = {31, 37};
  const T mod[2] = {1000000007, 1000000009};
  vector < T > h1, h2,  p_pow1, p_pow2;
 
  // calculate the powers of p
  void build_powers(const T &N){
    p_pow1 = p_pow2 = vector < T > (N + 1, 1);
    for (int i = 1; i <= N; ++i) {
      p_pow1[i] = (p_pow1[i - 1] * p[0]) % mod[0];
      p_pow2[i] = (p_pow2[i - 1] * p[1]) % mod[1];
    }    
  }
 
  // calculate the hash of a vector
  Hash(const vector < T > & v){
    int n = sz(v);
    build_powers(n + 5);
    h1 = h2 = vector < T > (n + 5, 1);
    for(int i = 1; i <= n; i++) {
      h1[i] = (h1[i - 1] * p[0] + v[i - !Base]) % mod[0];
      h2[i] = (h2[i - 1] * p[1] + v[i - !Base]) % mod[1];
    }
  }
 
  // calculate the hash of a string
  Hash(const string &s){
    int n = sz(s);
    build_powers(n + 5);
    h1 = h2 = vector < T > (n + 5, 1);
    for(int i = 1; i <= n; i++) {
      h1[i] = (h1[i - 1] * p[0] + s[i - !Base]) % mod[0];
      h2[i] = (h2[i - 1] * p[1] + s[i - !Base]) % mod[1];
    }
  }
 
  // calculate the hash of the position pos
  pair < T, T > at(constT &pos){
    return get_hash(pos, pos);
  }
 
  // calculate the hash of the substring s[l..r]
  pair < T, T > get_hash(const T &l, const T &r) {
    // hash of s[l..r] based on p1
    T F = h1[r];
    F -= h1[l - 1] * p_pow1[r - l + 1], F = ((F % mod[0]) + mod[0]) % mod[0];
    
    // hash of s[l..r] based on p1
    T S = h2[r];
    S -= h2[l - 1] * p_pow2[r - l + 1], S = ((S % mod[1]) + mod[1]) % mod[1];
    return {F, S};
  }
 
  bool is_same(const T &l1, const T &r1, const T &l2, const T &r2){
    return get_hash(l1, r1) == get_hash(l2, r2);
  }
  
  // merge the hashes of two substrings s1[l1..r1] and s2[l2..r2]
  pair < T, T > merge(const T &l1, const T &r1, const T &l2, const T &r2) {
    auto h1 = get_hash(l1, r1), h2 = get_hash(l2, r2);
    T F = (1LL * h1.first * p_pow1[r2 - l2 + 1] % mod[0] + h2.first) % mod[0];
    T S = (1LL * h1.second * p_pow2[r2 - l2 + 1] % mod[1] + h2.second) % mod[1];
    return {F, S};
  }
 
};
