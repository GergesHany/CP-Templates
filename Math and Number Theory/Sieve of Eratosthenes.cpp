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

  vector < ll > spf; 
  vector < vector < ll > > PrimeFactors; 

  void sieve(T N){
    spf = vector < T > (N + 5, 0);
    for (int i = 1; i < N; i++) spf[i] = (i & 1 ? 1 : 2);
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
