#define ll long long
#include <bits/stdc++.h>
using namespace std;

struct divisors{
    
    
    // function to Store all denominators
    void seive_number_of_divisors(){
   
        vector < int > divisor(1000005, 2);    
        divisor[0] = 0, divisor[1] = 1;
        for (int i = 2; i <= 1e6 / 2; i++)
            for (int j =  i * 2; j <= 1e6; j += i)
            divisor[j]++;
   
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
    vector < ll > get_all_divisors(ll n){
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


};
