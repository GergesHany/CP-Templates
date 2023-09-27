#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
const int mod = 1e9 + 7, N = 1e5 + 5;

int spf[N];
void sieve(){
  for (int i = 1; i < N; i++) spf[i] = i;
  for (int i = 2; i * i < N; i++){
    if (spf[i] == i){
      for (int j = i * i; j < N; j += i){
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}
 
template < typename T = int > struct Big_number{
  
  unordered_map < T, T > primes;

  Big_number(T n){
    assert(n > 0);
    mul(n);
  }

  void mul(T n){
    while (n > 1)
      primes[spf[n]]++, n /= spf[n];
  }

  void div(T n){
    while (n > 1)
      primes[spf[n]]--, n /= spf[n];
  }

  bool is_divisible(T x){
    while(x > 1){
      if (--primes[spf[x]] < 0) return false;
      x /= spf[x];
    }
    return true;
  }

};


int main(){ 




  return 0;
}