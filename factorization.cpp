template < typename T = int > struct factorization{

  // seive factorization
  void seive_factorization(T n){ 
    vector < T > divisors(n + 1, 2);
    divisors[0] = 0, divisors[1] = 1;
    for (int i = 2; i <= n / 2; i++)
        for (int j =  i * 2; j <= n; j += i) divisors[j]++;
  }

  void prime_factorization(int n){
      vector < T > prime_factors(n + 5);
      for (int i = 2; i <= 1e6; i++){ 
          if (!prime_factors[i]) { 
            for (int j = 2 * i; j <= 1e6; j += i) prime_factors[j]++;
            prime_factors[i] = 1; 
          }
      }
  }
    
  // get the number of divisors for n
  T number_of_divisors(T n){
    T cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
      if(n % i == 0){
        cnt++;
        if(i != n / i) cnt++;
      }
    }
    return cnt;
  }

    // get Summation of divisors for n
    T sum_of_divisors(T n){
      T sum = 0;
      for(int i = 1; i <= sqrt(n); i++)
          if(n % i == 0) sum += i + n / i;
      return sum - (sqrt(n) == (ll)sqrt(n)) * sqrt(n);
    }

    // get all divisors for n
    vector < T > get_divisors(T n){
        vector < T > divisors;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(i != n / i) divisors.push_back(n / i);
            }
        }
    }
    
 // to know more for this two function :: https://www.geeksforgeeks.org/sum-divisors-1-n

  // function to calculate sum of all divisors from [1, n] in O(n)
  T sumOfDivisors(T n) {
    T result = 0;
    for (ll i = 1; i <= n; i++) {
        result += (n / i) * i;
    }
    return result;
  }

  // function to calculate sum of all divisors from [1, n] in O(sqrt(n))
  T sum_divisors(T num){
      T sum = 0, sq = sqrt(num);
      for (ll i = 1; i <= sq; i++) {
      // sum of all divisors from [i, num / i]  
        T add1 = i * (num / i - i + 1);
        // sum of all divisors from [num / i + 1, num] = sum of all divisors from [1, num / i] - sum of all divisors from [1, i]
        T add2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2); 
        sum += add1 + add2;
      }
      return sum;
    }

};
