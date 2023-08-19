typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

template < typename T = int > struct Sieve{

    
  Sieve() = default;  

  vector < T > primes;
  vector < bool > is_prime;
  
  // constructor to build the seive
  Seive(T n){
    is_prime = vector < bool > (n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
  }

  // get all the prime numbers
  void get_primes(T n){
      for(int i = 2; i <= n; i++) 
          if(is_prime[i])          
              primes.push_back(i);
  }

  // display all the prime numbers
  void display(){
      for(auto prime_number: primes)
            cout << prime_number << " ";
      cout << "\n";
  }

};
