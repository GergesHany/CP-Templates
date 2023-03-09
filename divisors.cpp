#include <bits/stdc++.h>
#define ll long long

template < typename T = int > struct factorization{

    // seive factorization of all numbers from 1 to 1e6
    void seive_factorization(T n){ 
      vector < T > divisors(n + 1, 2);
        divisors[0] = 0, divisors[1] = 1;
        for (int i = 2; i <= n / 2; i++)
            for (int j =  i * 2; j <= n; j += i)
              divisors[j]++;
    }
    
    // get the number of divisors for n
    ll number_of_divisors(ll n){
        ll divisors = 0;
        for(int i = 1; i <= sqrt(n); i++)
            if(n % i == 0) divisors += 2;
        // 20  ->> 20 % 2 == 0 & 20 / 10 = 10 -> 20 % 10 == 0 ...
        return divisors - (sqrt(n) == (ll)sqrt(n));
    }

    // get Summation of divisors for n
    ll sum_of_divisors(ll n){
        ll sum_divisors = 0;
        for(int i = 1; i < sqrt(n); i++)
            if(n % i == 0) sum_divisors += ((n / i) + i);
         // 20  ->> 20 % 2 == 0 & 20 / 10 = 10 -> 20 % 10 == 0 ...
        return sum_divisors + ((ll)sqrt(n) * (ll)sqrt(n) == n ? (ll)sqrt(n) : 0);
    }

    // get all divisors for n
    vector < ll > get_divisors(ll n){
        vector < ll > divisors;
        for (int i = 1; i <= sqrt(n); i++){
            if (n % i == 0) 
            divisors.push_back(i),
            divisors.push_back(n / i);
        }
        if(sqrt(n) == (ll)(sqrt(n))) 
            divisors.pop_back();
        return divisors;
    }
    
        
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

};
