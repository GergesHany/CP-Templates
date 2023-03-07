typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

template < typename T = int > struct Seive{

    
  Seive() = default;  

  vector < T > primes;
  vector < bool > is_prime;
  
  // check the number 
  Seive(int n){
    is_prime = vector < bool > (n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= n; i++)
      if(is_prime[i])
        for(ll j = i * 2; j <= n; j += i)
          is_prime[j] = false;
  }

  // build function to get all prime number from 1 to n 
  void get_primes(int n){
      for(int i = 2; i <= n; i++) 
          if(is_prime[i])          
              primes.push_back(i);
  }

  // print a prime number 
  void display(){
      for(auto prime_number: primes)
            cout << prime_number << " ";
      cout << "\n";
  }

};
