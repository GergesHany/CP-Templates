#include <bits/stdc++.h> 
using namespace std; 

  
typedef long long ll;

// spf to store the smallest prime factor for each number from 1 to N,
vector < ll > spf; 

// PrimeFactors to store the prime factors of each number from 1 to N.
vector < vector < ll > > PrimeFactors; 

// calculate the prime factors of N. 
vector < ll > Prime_Factors(ll N){
    vector < ll > ret;
    while(N > 1){
      ret.push_back(spf[N]);
      N /= spf[N];
    }
    return ret;
}

void sieve(ll N){
  
  spf = vector < ll > (N + 5, 0);
  PrimeFactors = vector < vector < ll > > (N + 5);

  spf[0] = spf[1] = 1; // 0 and 1 are not prime numbers. they are special cases.

  // Marking smallest prime factor for every number to be itself.
  for(int i = 2; i < N; i++) spf[i] = i;

  // separately marking spf for every even number as 2. 
  for (int i = 2; i < N; i += 2) spf[i] = 2;
      
  // Iterating over all odd numbers.
  for (ll i = 3; i * i < N; i++) { 
    if (spf[i] == i) { 
      for (ll j = i * i; j < N; j += i) 
        if (spf[j] == j) 
          spf[j] = i; 
    } 
  }    

  // Calculating the prime factors of each number from 1 to N.
  for (ll i = 1; i < N; i++)
    PrimeFactors[i] = Prime_Factors(i);

}


int main()
{ 



  return 0;
}
 