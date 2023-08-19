typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

struct Big_int{
    Big_int(){}


    // get a mod for big int

    ll Big_Mod(string s, ll mod){
        ll res = 0;
        for(auto& c : s)
            res = (res * 10 + (c - '0')) % mod;
        return res;
    }

    //  sum two big number with string
    string BigAdd(string s, string t){
        string res;
        int sz = max(s.size(), t.size());
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        char carry = '0';
        int e = 0, f = 0;
        for(int i = 0; i < sz || carry != '0'; i++){
        e = (i >= s.size() ? 0 : s[i] - '0');
        f = (i >= t.size() ? 0 : t[i] - '0');
        int tmp = (carry - '0') + e + f;
        carry = (tmp / 10) + '0';
        res.push_back(tmp % 10 + '0');
        }
        reverse(res.begin(), res.end());
        while(res[0] == '0') res.erase(res.begin());
        return res;
    }
    
     // mulipuly two big number with string
    string BigMulti(string s, string t){
        string res;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        for(int i = 0; i < t.size(); i++){
        string tmp = string(i, '0');
        char carry = '0';
        for(int j = 0; j < s.size(); j++){
            int m = (t [i] - '0') * (s[j] - '0') + (carry - '0');
            carry = (m / 10) + '0';
            tmp.push_back(m % 10 + '0');
        }
        tmp.push_back(carry);
        reverse(tmp.begin(), tmp.end());
        res = BigAdd(res, tmp);
        }
        while(res[0] == '0') res.erase(res.begin());
        return res;
    }

    // mulipuly two big number and take mod without overflow  
    ll mul(ll a, ll b, ll mod) {
        ll res = 0;
        while (b) {
            if (b & 1) res = (res + a) % mod;
            a = (a + a) % mod;
            b >>= 1;
        }
        return res;
    }

    // sum two big numbers and take mod without overflow 
    ll sum(ll a, ll b, ll mod) {
        return (a + b) % mod;
    }  


};
