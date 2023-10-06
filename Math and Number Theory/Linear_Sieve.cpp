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

};

