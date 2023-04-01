struct factorization{

  // seive factorization
  void seive_factorization(int n){ 
    vector < int > divisors(n + 1, 2);
    divisors[0] = 0, divisors[1] = 1;
    for (int i = 2; i <= n / 2; i++)
        for (int j =  i * 2; j <= n; j += i) divisors[j]++;
  }

  void prime_factorization(int n){
      vector < int > prime_factors(n + 5);
      for (int i = 2; i <= 1e6; i++){ 
          if (!prime_factors[i]) { 
            for (int j = 2 * i; j <= 1e6; j += i) prime_factors[j]++;
            prime_factors[i] = 1; 
          }
      }
  }
    
  // -----------------------------------------------------------------------------------------------------------------------------------
  
  // get the number of divisors for n
  ll number_of_divisors(ll n){
    ll cnt = 0;
    for(int i = 1; i <= sqrt(n); i++){
      if(n % i == 0){
        cnt++;
        if(i != n / i) cnt++;
      }
    }
    return cnt;
  }

    // get Summation of divisors for n
    ll sum_of_divisors(ll n){
      ll sum = 0;
      for (int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
          sum += i;
          if (i != n / i) sum += n / i;
        }
      }
      return sum;
    }

    // get all divisors for n
    vector < ll > get_divisors(ll n){
        vector < int > divisors;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(i != n / i) divisors.push_back(n / i);
            }
        }
    }
  
 // ----------------------------------------------------------------------------------------------------------------------------------- 
    
 // to know more for this two function :: https://www.geeksforgeeks.org/sum-divisors-1-n

  // function to calculate sum of all divisors from [1, n] in O(n)
  ll sumOfDivisors(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        result += (n / i) * i;
    }
    return result;
  }

  // function to calculate sum of all divisors from [1, n] in O(sqrt(n))
  ll sum_divisors(ll num){
      ll sum = 0, sq = sqrt(num);
      for (ll i = 1; i <= sq; i++) {
      // sum of all divisors from [i, num / i]  
        ll add1 = i * (num / i - i + 1);
        // sum of all divisors from [num / i + 1, num] = sum of all divisors from [1, num / i] - sum of all divisors from [1, i]
        ll add2 = (((num / i) * (num / i + 1)) / 2) - ((i * (i + 1)) / 2); 
        sum += add1 + add2;
      }
      return sum;
    }
  
  
  // -----------------------------------------------------------------------------------------------------------------------------------
  
  // any number can be represented as a product of prime factors 
  // for example 12 = (2^2) * (3^1) the number of divisors of 12 is (2 + 1) * (1 + 1) = 6 
  // the number of divisors of n! is the (product of the number of divisors of each prime factor) + 1 from 1 to n

  ll number_of_divisors(ll n){
    ll ans = 1;
    ll freq[1005] {};

    // find the prime factors of n and count the number of times each prime factor appears
    for (ll i = n; i >= 1; i--){
      ll val = i; // val is the number that we will factorize
      for (ll j = 2; j <= val; j++)
         // if j is a prime factor of val then count the number of times it appears
         while(val % j == 0) freq[j]++, val /= j;
    }

    for (ll i = 1; i <= n; i++){
     // multiply the number of divisors of each prime factor by the number of divisors of n! 
      ans *= (freq[i] + 1);
    }

    return ans;
  }
  

};
