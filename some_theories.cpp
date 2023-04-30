#include <bits/stdc++.h>
using namespace std;
#define ll long long 

// Extended Euclidean theory

ll x = 0, y = 0; 
ll Extended_Euclidean(ll a, ll b){ // recursive
  if (b == 0){
    x = 1, y = 0;
    return a;
  }
  ll d = Extended_Euclidean(b, a % b);
  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1, y = y1;
  return d;
}

ll Extended_Euclidean(ll a, ll b){ // iterative
  x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1){
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

// ---------------------------------------------------------------

// Euler's totient function

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
          while (n % i == 0)
              n /= i;
          result -= result / i;
      }
  }
  if (n > 1)
      result -= result / n;
  return result;
}

// Euler totient function from 1 to n in O(nloglogn)

void phi_1_to_n(int n) {
  vector < int > phi(n + 1);
  for (int i = 0; i <= n; i++)
      phi[i] = i;

  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
        for (int j = i; j <= n; j += i)
            phi[j] -= phi[j] / i;
    }
  }
}

// Euler totient function from 1 to n in O(n log n)
void phi_1_to_n(int n) {
  vector<int> phi(n + 1);
  phi[0] = 0, phi[1] = 1;
  for (int i = 2; i <= n; i++)
      phi[i] = i - 1;

  for (int i = 2; i <= n; i++)
      for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
}

// ---------------------------------------------------------------

// Mobius function

// Mobius function from 1 to n in O(nloglogn)

void mobius_1_to_n(ll n){

  const int N = 1e6 + 5;
  vector < int > mu(N, 1);
  vector < bool > is_prime(N, true);
  for (int i = 2; i < N; i++) if (is_prime[i]) 
      for (int j = i; j < N; j += i) 
        is_prime[j] = false, mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);
  
}

// Mobius function for a number in O(sqrt(n))
ll mobius(ll n){
  ll ans = 1;
  for (ll i = 2; i * i <= n; i++){
    if (n % i == 0){
      ll cnt = 0;
      while (n % i == 0)
        n /= i, cnt++;
      if (cnt > 1)
        return 0;
      ans *= -1;
    }
  }
  if (n > 1)
    ans *= -1;
  return ans;
}

int main(){


  return 0;
}
