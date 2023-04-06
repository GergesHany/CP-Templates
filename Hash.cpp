template < typename T = long long > struct Hash {
 
  T N;
  const int p[2] = {31, 37};
  const int mod[2] = {1000000007, 1000000009};
  vector < T > h1, h2,  inv1, inv2, p_pow1, p_pow2;
 
 
  T bpow(T n, T x, T m) {
    return !x ? 1 : 1LL * bpow(n * n % m, x >> 1, m) * (x & 1 ? n : 1) % m;
  }
 
  Hash(T N){
    this -> N = N;
    h1 = h2 = inv1 = inv2 = p_pow1 = p_pow2 = vector < T > (N);
    p_pow1[0] = p_pow2[0] = 1, inv1[1] = inv2[1] = 1;
    ll inv_p1 = bpow(p[0], mod[0] - 2, mod[0]), inv_p2 = bpow(p[1], mod[1] - 2, mod[1]);
    for (T i = 1; i < N; i++) {
      p_pow1[i] = (1LL * p_pow1[i - 1] * p[0]) % mod[0];
      p_pow2[i] = (1LL * p_pow2[i - 1] * p[1]) % mod[1];
      inv1[i] = (1LL * inv1[i - 1] * inv_p1) % mod[0];
      inv2[i] = (1LL * inv2[i - 1] * inv_p2) % mod[1];
    }
  }
 
  void build(string &s) {    
    h1[0] = h2[0] = s[0] - 'a' + 1;
    for (T i = 1; i < sz(s); i++) {
      h1[i] = (1LL * h1[i - 1] * p[0] + s[i] - 'a' + 1) % mod[0];
      h2[i] = (1LL * h2[i - 1] * p[1] + s[i] - 'a' + 1) % mod[1];
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
 
};
