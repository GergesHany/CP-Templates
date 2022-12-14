#define EPS 1e-9
typedef long long ll;
typedef long double ld;
#define Mod 1'000'000'007
#define all(s) s.begin(), s.end()
#include <bits/stdc++.h>
using namespace std;

struct Some_Math{
    Some_Math(){}

    // Greatest common divisors between two numbers
    ll GCD(ll a, ll b){
        return (!b ? a : GCD(b, a % b));
        // ->> n = GCD(ll a, ll b) ->> (a + b) % n = 0 && (a - b) % n = 0
    }
    
    // least common multiplication between two numbers
    ll LCM(ll a, ll b){
        return a / GCD(a, b) * b;
    }
 
     // find numbner k is not divisible by n
    int kthNonDivisible(int N, int K){
      return K + floor((K - 1) / (N - 1));
    }

    // summation between 1 and n
    ll summation(ll n){
        return n * (n + 1) / 2;
    }

    // sum even number in the number
    ll sum_Even(ll n){
        return (n / 2 * (n / 2 + 1));
    }

    // sum odd number in the number
    ll sum_Odd(ll n){
       return summation(n) - sum_Even(n);
    }

    // find factorial of the number
    ll factorial(ll n){
        return (n == 1 ? 1 : n * factorial(n - 1));
    }
     
    // count square and cube num 1 to n 
    ll count_square_and_cube(ll n){
         return (ll)sqrt(n) + (ll)cbrt(n) - (ll)(sqrt(cbrt(n)));
    }
     
    // Check for each point check whether it belongs to the rectangle or not (n, m)
    bool  Rectangle(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, ll n, ll m){
        ll MAN_X = max({x1,x2,x3,x4}),  MIN_X = min({x1,x2,x3,x4});
        ll MAN_y = max({y1,y2,y3,y4}),  MIN_y = min({y1,y2,y3,y4});
        return (n >= MIN_X and n <= MAN_X and m >= MIN_y and m <= MAN_y);
   }
 
   // check the number is prime or not prime 
   bool is_prime(ll n){
     if (n <= 1) return false;
     if (n <= 3) return true;
     if (n % 2 == 0 or n % 3 == 0) return false;
     for (ll i = 5; i * i <= n; i += 6){
        if (n % i == 0 or n & (i + 2) == 0) return false;
     }
     return true;  
   }

   // check the number is prime or not O(sqrt(n))
    bool is_prime(ll n){
        if(n < 2 || (n % 2 == 0 && n != 2)) return false;
        for(int i = 3; i <= sqrt(n); i += 2)
            if(n % i == 0) return false;
        return true;
    }

   // check the number is power of two or not 
   bool power_of_2(ll n){
     return log2(n) == (ll)log2(n);
   }

   // check the number is Perfect Square or not 
    bool PerfectSquare(long double x) {    
        return (sqrtl(x) * sqrtl(x)) == x;
    } 

    // Check if it valid triangle 
    bool is_triangle(ll a, ll b, ll c){
       return (a + b > c) && (a + c > b) && (b + c > a) && (a && b && c);
    }
 
    // Get Slope of two points
    double slope(double x1, double y1, double x2, double y2){
        if(x2 - x1 == 0) return INT_MAX; // divisble by zero 
        return (y2 - y1) / (x2 - x1);
    }

    // multiply two number and take mod for them
    ll multiply(ll a, ll b){
        return ((a % Mod) * (b % Mod)) % Mod; // Mod = 1e9 + 7
    }

    // summation two number and take mod for them
    ll sum(ll a, ll b){
        return ((a % Mod) + (b % Mod)) % Mod; // Mod = 1e9 + 7
    }

    // b power e in O(log(n))

    ll fast_pow(ll b, ll e){
        ll power = 1;
        while(e){
            if(e % 2) power *= b;
            e /= 2; b *= b;
        }
        return power;
    }

    // b power e % mod in O(log(n))

    ll fast_pow(ll b, ll e){
        ll power = 1;
        while(e){
            if(e % 2) power = ((power % Mod) * (b % Mod)) % Mod;
            e /= 2; b = ((b % Mod) * (b % Mod)) % Mod;
        }
        return power % Mod; // Mod = 1'000'000'007
    }

    //  get the summation between two numbers
    ll summation(ll n, ll m){
        if (m > n)           swap(n, m);
        return (n * (n + 1) / 2) - (m * (m - 1) / 2);
        //  m * (m - 1) / 2 ->> = (m * (m + 1) / 2) - m
    }

    // compare between two double number
    ll cmp_double(double a, double b){
    // if very small different, then equal
      if (fabs(a - b) <= EPS) return 0;
      return (a > b ? 1 : -1);
      // EPS = 1e-9
    } 

    // Combination
    ll nCr(ll n, ll r){  // nCr = n! / (r! * (n-r)!)
        if (r > n)  return 0;
        if (n == r or r == 0) return 1;
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }

    // Permutation
    ll nPr(ll n, ll r){ // // nPr = n! / (n - r)!
        ll ans = 1;
        for (ll i = (n - r) + 1; i <= n; i++){
            ans *= i; ans %= 1000000007;
        }
        return ans;
    }
    
    // number of even numbers between a and b
    ll get_even(ll a, ll b){
      return (b / 2) - ((a - 1) / 2);
    }

    // number of odd numbers between a and b
    ll get_odd(ll a, ll b){
      return ((b - a) + 1) - get_even(a, b);
    }


    // ----------------> some notes ---------------->>
    // ceill(x, y) = (x + y - 1) / y;
    // round x > 0 ? (x + y / 2) / y : (x - y / 2) / y;

    // increasing 1 2 3 4 5 5 6 6 -> have a more than frequency
    // strictly increasing 1 2 3 4 5 6 -> not have a more than frequency

    // logx(n * m) = logx(n) + logx(m);
    // logx(n / m) = logx(n) - logx(m);
    // logx(pow(n, m)) = m * logx(n);
    // log(n * m) = log(n) + log(m) ->> the base is e

    // a % n == b % n = (a - b) % n ->> n (a - b)
    // (a + b) % n = (a % n + b % n) % n
    // (a % b) = c ->> a -= c ->> a is a multiply for b
    // ex ->> 13 % 4 = 1 ->> 13 - 1 = 12 ->> 12 / 3 = 4 
    // (n ^ x) % n == 0 ->> for all x > 0

    // count number of prime 1 to n ->> ~= n / log(n) 
    // (p - 1)! % p = p - 1 ->> for all p is prime number
    // n! % x == 0 for all x <= n
    // 2! is onle prime factorization 

    // GCD(1, num) = 1
    // LCM(1, num) = num

};
