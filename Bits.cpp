#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 2'000'000'000
#define Mod 1'000'000'007
#define sz(s) int(s.size())
const int N = 2 * 1e5 + 5;
const int size = (1e8 / 8) + 1; // size of bit array
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()

int n;
vector < ll > vec(N);


// >> shift right operator (divide by 2)
// << shift left operator (multiply by 2)
// & bitwise and operator (1 if both bits are 1) 
// | bitwise or operator (1 if at least one bit is 1)
// ^ bitwise xor operator  (1 if only one bit is 1)
// ~ bitwise not operator (1 to 0 and 0 to 1)

// (x ^ y) = z and x = (z ^ y) and y = (z ^ x)

// __builtin_clz(n) count leading zeros
// __builtin_ctz(n) count trailing zeros
// __builtin_popcount(n) count set bits
// << -> shift all bits to the left by n 
// >> -> shift all bits to the right by n

// __lg(n) = floor(log2(n))
// __lg(n) = fls(n) - 1
// __lg(n) = 32 - __builtin_clz(n)
// __lg() -> find the left most set bit
// (n & -n) = (lsp) -> find the right most set bit in n (least significant bit) (the lowest power of 2 that is a factor of n)
// __lg() = (msb) -> find the largest power of 2 that is less than or equal to n


struct Bits{
    

    // get Bit at index 
    bool getbit(ll n, ll index){  
        return ((n >> index) & 1);
    }

    ll getbit_value(ll n, ll index){  
        return (n >> index) & 1;
    }

    // set Bit at index
    ll setBit(ll n, ll index){   
        return (n | (1LL << index));
    }

    // close Bit at index
    ll clousebits(ll n, ll index){
        return n & (~(1LL << index));
    }
    
    // close bit at index 
    ll clousebits(ll n, ll index){
        return n & (UINT_MAX ^ (1LL << index));
    }

    // flip bit at index
    ll flibBit(ll n, ll index){
        return n ^ (1LL << index);
    }

    // function to convert number to binary
    string binary(ll n){
        string s;
        while(n)
            s += (n & 1) + '0', n >>= 1;
        reverse(all(s));
        return s;
    }

    // function to close the right most set bit
    ll close_right_one(ll n){
        return (n & (n - 1));
    }

     // function get the value of the last bit
    ll countbist(ll n){ // O(log n) ->> __builtin_popcount(n)
        ll cnt = 0;
        while(n > 0){
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

    // count bit in the number 
    ll countbist(ll n){ // O(countbist(n))
        ll cnt = 0;
        while((n &= (n - 1))) cnt++;
        return ++cnt;
    }

    // function get the value of the last bit
    ll lastbitvalue(ll n){
        ll Idx = 0;
        while(n &= (n - 1)) Idx++;
        return (1LL << Idx);
    }

    // function get the value of the last bit
    ll lastbitvalue_1(ll num){
        return (num & ~(num - 1));
    }

    // find the power of 2 that is graeter than n
    ll power_of_two(ll n){
        ll index = 0;
        while(1LL << index <= n) index++;
        return 1 << index;
    }
 
    // count diffrent bits between two numbers 
    ll hamming_distance(ll x, ll y){
        ll var = x ^ y, dis = 1;
        while(var &= (var - 1)) dis++;
        return dis;
    }


   // find Xor range [l .. r]
   int findXOR(int n){
      vector < int > arr = {n, 1, n + 1, 0};
      return arr[n % 4];
    }
 
    int findXOR(int l, int r){
        return (findXOR(max(0, l - 1)) ^ findXOR(r));
    }

    // function to check if the number is power of 2
    bool isPowerOfTwo(ll num) {
        return (num & num - 1) == 0 && num > 0;
    }

    // function to get all subset 
    void get_all_subset(){   // n <= 22
        for (int i = 1; i < (1 << n); i++){
            for (int j = 0; j < n; j++){
                if (((i >> j) & 1))
                    cout << vec[j] << " ";
            }
            cout << "\n";
        }
    }

    // example for meet in the middle
    void Meet_in_Middle(){ // n <= 40
        ll n;
        cin >> n;
        vector < ll > vec(n);
        for (auto& i: vec) cin >> i;
        int lhalf = n / 2;
        int rhalf = n - lhalf;
        ll ans = 0;
        map < ll, ll > freq;
        for (int i = 0; i < rhalf; i++){
            ll _xor = 0;
            for (int j = 0; j < rhalf; j++){
              if (((i >> j) & 1)) _xor ^= vec[j + lhalf];  
            }
            freq[_xor]++;
        }

        for (int i = 0; i < lhalf; i++){
            ll _xor = 0;
            for (int j = 0; j < lhalf; j++){
              if (((i >> j) & 1)) _xor ^= vec[j];  
            }
            ans += freq[_xor];
        }
        cout << ans << "\n";
    }
    
    int gray_code(int n){
        return n ^ (n >> 1);
    }

   // function to find Max Xor Two number between range 
    int maxXORInRange(int L, int R){
        int LXR = L ^ R,  msbPos = 0;
        while (LXR) msbPos++, LXR >>= 1;
        return (pow(2, msbPos) - 1);
   }

  // function to find Max Xor Two number in array
  void find_maxXor(){
    vector < ll > nums;
    ll mask = 0, Max = 0;
    for (int i = 31; i >= 0; i--){
        mask |= (1ll << i);
        set < ll > st;
        for (auto& i: nums) st.insert(i & mask);
        ll test = Max | (1 << i);
        for (auto& j: st){
            if (st.find(test ^ j) != st.end()){
                Max = test;
                break; 
            }
        }
    }
    cout << Max;
  }
  
  // msp = most significant bit position
    int msp(int n){
        int pos = 0;
        while (n) pos++, n >>= 1;
        return pos;
    }

    // lsb = least significant bit position
    int lsb(int n){
        return (n & -n);
    }
    
    // example of using bitset to mark visited numbers in range [0, 10^7] 

    void visited_array(){


      const int size = 12500000;
      char visited[size + 1] = {false};

      int n, q, x;   cin >> n;

      auto setBit = [&](ll n, ll index) -> ll {   
        return (n | (1LL << index));
      };

      auto getBit = [&](ll n, ll index) -> bool {
        return (n & (1LL << index));
      };

      for (ll i = 0, val; i < n && cin >> val; i++){
        // set bit in visited array to 1
        // val / 8 to get the index of the byte
        // val % 8 to get the index of the bit in the byte and set it to 1
        visited[val >> 8] = setBit(visited[val / 8], val & 7);
      }

      cin >> q;
      while(q-- && cin >> x){
        // get the bit in visited array 
        // val / 8 to get the index of the byte
        // val % 8 to get the index of the bit in the byte and get it
        // if the bit is 1 then the number is visited else not visited
        cout << (getBit(visited[x >> 8], x & 7) ? "YES" : "NO") << "\n";
      }  

    }

};
