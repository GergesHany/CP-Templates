#define EPS 1e-9
typedef long long ll;
typedef long double ld;
#define Mod 1'000'000'007
#define all(s) s.begin(), s.end()
#define sz(s) int(s.size())
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
    bool PerfectSquare(ll x) { 
        ll temp = x;
        return temp * temp == x;
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
    
    // function to calculate sum of powers of x from 1 to n
    ll sum_powers(ll x, ll n, ll mod){
      if (n == 1) return x % mod;
      ll power = sum_powers(x, n / 2, mod);
      ll ans = (power + (power * fast_pow(x, n / 2, mod))) % mod;
      if (n & 1) ans = (ans + fast_pow(x, n, mod)) % mod;
      return ans;
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
    ll ncr(ll n, ll r){ // nCr = n! / (r! * (n-r)!)
      if(r > n) return 0;
      if(r > n - r) r = n - r;
      ll ans = 1;
      for(ll i = 1; i <= r; i++){
        ans *= n - r + i;
        ans /= i;
      }
      return ans;
    }

    // Permutation
    ll nPr(ll n, ll r){ // // nPr = n! / (n - r)!
        ll ans = 1;
        for (ll i = (n - r) + 1; i <= n; i++){
            ans *= i; ans %= Mod;
        }
        return ans;
    }
    
    // number of even numbers between a and b
    ll get_even(ll a, ll b){
      return (b / 2) - ((a - 1) / 2);
    }

    // number of odd numbers between a and b
    ll get_odd(ll a, ll b){
      return (b + 1) / 2 - (a / 2) - (!a);
    }
    
     // function to rotate a point by k degrees 
    pair < double, double > rotate(pair < double, double > point, ll k){
      long double PI = 3.14159265358979323846;
      ld angle = k * PI / 180;
      ld x = point.first * cos(angle) - point.second * sin(angle);
      ld y = point.first * sin(angle) + point.second * cos(angle);
      return make_pair(x, y);
    }
    
    // fucntion to convert decimal to any base
    string decimal_to_any_base(ll n, ll base){
      string ans;
      if (n == 0) return "0";
      string num = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      while (n){
        ans += num[n % base];
        n /= base;
      }
      reverse(all(ans));
      return ans;
    }

    // function to convert any base to decimal
    ll any_base_to_decimal(string s, ll base){
      ll ans = 0;
      auto val = [&](char c){
        return (isdigit(c) ? c - '0' : c - 'A' + 10);
      };

      ll power = 1;
      for (int i = sz(s) - 1; i >= 0; i--){
        ans += val(s[i]) * power;
        power *= base;
      }
      return ans;
    }
    
    //  Check if number power of another or not
    bool is_power(ll n, ll k) {
      if (n == 1) return true;
      if (n % k != 0) return false;
      return is_power(n / k, k);
    }
    
    // function to get the log of any base
    double get_log(ll n, ll base){
      return (ll)(log(n) / log(base));
    }

    // function to Check if number power of another or not
    bool is_power(ll n, ll base){
      return get_log(n, base) * log(base) == log(n);
    }
    

    // sum (i * (i + 1)) from 1 to n = n * (n + 1) * (2 * n + 1) / 6 
    ll summation(ll x){
      return ((x * (x + 1) * (2 * x + 1) / 6) + (x * (x + 1) / 2));
    }
    
    // find the reverse sum of a number
    ll rev_sum(ll sum){
      return sqrt(0.25 + 2 * sum) - 0.5;
    }

    ll rev_sum(ll sum){
      return (-1 + sqrt(1 + 8 * sum)) / 2;
    }

    // (2 4 6 8) , (1 3 5 7) , (1 4 7 10) .....
    // summation of arithmetic sequence increase with constant number
    ll arithmetic_summation(ll first = 1, ll last = 1){
      ll x = last - first + 1;
      return ((first + last) * x) / 2;
    }
    
    // (1 4 16), (1 3 9)...
    // get kth element in sequence increase by multiple of constant
    ll kth(ll first, ll ratio, ll k){
      // ratio -> the constant number
      auto fast_pow = [&](ll base, ll power){
        ll res = 1;
        while(power){
          if(power & 1) res = (res * base);
          base = (base * base);
          power >>= 1;
        }
        return res;
      };
      return first * fast_pow(ratio, k - 1);
    }
    
    // 1 4 16 ,, 1 3 9...
    // get a summation of geometry sequence increase by a multiple of a constant
    ll geometry_summation(ll first, ll ratio, int number_of_element){
      return ((first * (1 - pow(ratio, number_of_element))) / (1 - ratio));
    }

    // number of ways to make a vector of size n and the maximum element is x
    auto number_of_ways = [&](ll x, int n) -> ll {
      ll ans = fast_pow(x, n) - fast_pow(x - 1, n);
      ans = (ans + mod) % mod;
      return ans;
    };

        
    // ----------------> some notes ---------------->>
    // ceill(x, y) = (x + y - 1) / y;
    // round x > 0 ? (x + y / 2) / y : (x - y / 2) / y;

    // increasing 1 2 3 4 5 5 6 6 -> have a more than frequency
    // strictly increasing 1 2 3 4 5 6 -> not have a more than frequency

    // logx(n * m) = logx(n) + logx(m);
    // logx(n / m) = logx(n) - logx(m);
    // logx(pow(n, m)) = m * logx(n);
    // log(n * m) = log(n) + log(m) ->> the base is e
    // log(fact(5)) = log(5!) = log(5 * 4 * 3 * 2 * 1) = log(5) + log(4) + log(3) + log(2) + log(1)   


    // a % n == b % n = (a - b) % n ->> n (a - b)
    // (a + b) % n = (a % n + b % n) % n
    // (a % b) = c ->> a -= c ->> a is a multiply for b
    // ex ->> 13 % 4 = 1 ->> 13 - 1 = 12 ->> 12 / 3 = 4 
    // (n ^ x) % n == 0 ->> for all x > 0
    
    // segma f(2 ^ x) = 2 ^ (x + 1) - 1

    // n! % x == 0 for all x <= n
    // 2! is onle prime factorization 
    // count number of prime 1 to n ->> ~= n / log(n) 
    // Wilson theorem for prime numbers (n - 1)! % n = n - 1 if n is prime
    // The perfect square number the prime factorization of the number is even and the number of divisors is odd


    // GCD(1, num) = 1
    // LCM(1, num) = num

};
