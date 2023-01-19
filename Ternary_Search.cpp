#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef long double ld;


struct Ternary_Search{

  // example function
  ld F(ld x){
    // 
  }

  // ternary search
  ld ternary_search(ld L, ld R){
    ld l = L, r = R, EPS = 1e-9;
    while(r - l > EPS){ 
        ld g = l + (r - l) / 3, h = r - (r - l) / 3;
        if(F(g) == F(h)) l = g, r = h;
        else (F(g) < F(h) ? r = h : l = g);
    }

    ld ans = F(l);
    return ans;
  }


  ll F(ll n){
    // 
  }

  ll ternary_search(ll L, ll R){
    ld l = L, r = R, EPS = 1e-9;
    while(r - l > 5){ 
        ld g = l + (r - l) / 3, h = r - (r - l) / 3;
        if(F(g) == F(h)) l = g, r = h;
        else (F(g) < F(h) ? r = h : l = g);
    }

    ll ans = F(l++);
    for (ll i = l; i <= r; i++){
      ans = min(ans, F(i));
    }
    return ans;
  }

};

int main()
{


  return 0;
}