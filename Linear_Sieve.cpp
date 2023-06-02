template < typename T = int > struct Linear_Sieve{

  Linear_Sieve() = default;
  
  vector < T > lp, pr;

  // constructor to generate all primes from 1 to N on O(N) 
  Linear_Sieve(T N){
    lp = vector < T > (N + 1, 0);
    for (T i = 2; i <= N; ++i){
      if (!lp[i]) lp[i] = i, pr.push_back(i);
      for (T j = 0; j < sz(pr) && pr[j] <= lp[i] && i * pr[j] <= N; ++j) lp[i * pr[j]] = pr[j];
    }
  }

  // function to check if a number n is prime
  bool isPrime(T n){
    return (n > 1 && lp[n] == n);
  }

  // function to generate all prime factors of a number n on O(log(n))
  vector < T > factorize(T n){
    vector < T > fac;
    while (n > 1){
      fac.push_back(lp[n]);
      n /= lp[n];
    }
    return fac;
  }

  // function to generate all divisors of a number n on O(2 ^ (number of prime factors of n))
  set < T > divisors(T n){
    ste < T > divs = {1};
    vector < T > fac = factorize(n);
    for (T i = 0, j, sz; i < (1 << sz(fac)); ++i){
      for (j = 0, sz = 1; j < sz(fac); ++j){
        if (i & (1 << j)) sz *= fac[j];
      }
      divs.insert(sz);
    }
    return divs;
  }

};

