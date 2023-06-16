template < typename T = int > struct Sieve_of_Eratosthenes{
  
  Sieve_of_Eratosthenes() = default;

  Sieve_of_Eratosthenes(T N, bool store = false){
    sieve(N);
    if(store){
      PrimeFactors = vector < vector < T > > (N + 5);
      for(int i = 1; i <= N; i++){
        PrimeFactors[i] = Prime_Factors(i);
      }
    }
  }

  // spf to store the smallest prime factor for each number from 1 to N,
  vector < ll > spf; 

  // PrimeFactors to store the prime factors of each number from 1 to N.
  vector < vector < ll > > PrimeFactors; 

  void sieve(T N){
    
    spf = vector < T > (N + 5, 0);
    spf[0] = spf[1] = 1; // 0 and 1 are not prime numbers. they are special cases.

    // Marking smallest prime factor for every number to be itself.
    for(int i = 2; i < N; i++) spf[i] = i;

    // separately marking spf for every even number as 2. 
    for (int i = 2; i < N; i += 2) spf[i] = 2;
        
    // Iterating over all odd numbers.
    for (T i = 3; i * i < N; i++) { 
      if (spf[i] == i) { 
        for (T j = i * i; j < N; j += i) 
          if (spf[j] == j) 
            spf[j] = i; 
      } 
    }    

  }

  vector < T > Prime_Factors(T N){
    vector < T > ret;
    while(N > 1){
      ret.push_back(spf[N]);
      N /= spf[N];
    }
    return ret;
  }

  vector < T > Factors(T n){
    return PrimeFactors[n];
  }

};
