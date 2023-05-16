template < typename T = long long > struct Hash {
 
  T N;
  const int p[2] = {31, 37};
  const int mod[2] = {1000000007, 1000000009};
  vector < T > h1, h2,  p_pow1, p_pow2;
 
  Hash(T N){
    this -> N = N;
    h1 = h2 = p_pow1 = p_pow2 = vector < T > (N);
    p_pow1[0] = p_pow2[0] = 1;
    for (T i = 1; i < N; i++) {
      p_pow1[i] = (1LL * p_pow1[i - 1] * p[0]) % mod[0];
      p_pow2[i] = (1LL * p_pow2[i - 1] * p[1]) % mod[1];
    }
  }
 
  void build(string &s) {    
    h1[0] = h2[0] = s[0] - 'a' + 1;
    for (T i = 1; i < sz(s); i++) {
      h1[i] = (1LL * h1[i - 1] * p[0] + s[i] - 'a' + 1) % mod[0];
      h2[i] = (1LL * h2[i - 1] * p[1] + s[i] - 'a' + 1) % mod[1];
    }
  }

  void build(vector < T > &v) {    
    h1[0] = h2[0] = v[0];
    for (T i = 1; i < sz(v); i++) {
      h1[i] = (1LL * h1[i - 1] * p[0] + v[i]) % mod[0];
      h2[i] = (1LL * h2[i - 1] * p[1] + v[i]) % mod[1];
    }
  }

  pair < T, T > get_hash(T l, T r) {
    // first = hash of s[l..r] based on p1
    T F = h1[r];
    if (l) F = (F - 1LL * h1[l - 1] * p_pow1[r - l + 1] % mod[0] + mod[0]) % mod[0];
    // second = hash of s[l..r] based on p2
    T S = h2[r];
    if (l) S = (S - 1LL * h2[l - 1] * p_pow2[r - l + 1] % mod[1] + mod[1]) % mod[1];
    return {F, S};
  }

  pair < T, T > at(T pos) {
    return get_hash(pos, pos);
  }

  bool is_same(T l1, T r1, T l2, T r2) {
    return get_hash(l1, r1) == get_hash(l2, r2);
  }
 
};
