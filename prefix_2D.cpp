#include <iostream>
#include <vector>
#define ll long long
#define sz(x) (int)x.size()
using namespace std;


struct prefix_sum_2d{
  
  // build prefix sum 2d
  vector < vector < ll > > prefix_sum(vector < vector < ll > > &v){
    int n = sz(v), m = sz(v[0]);
    vector < vector < ll > > ps(n + 1, vector < ll > (m + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ps[i][j] = v[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }
    return ps;
  }

  // query in prefix sum 2d
  ll query(vector < vector < ll > > &ps, int x1, int y1, int x2, int y2){
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1];
  }
  
  // print prefix sum 2d
  void print(vector < vector < ll > > &ps){
    for (int i = 1; i < sz(ps); i++)
        for (int j = 1; j < sz(ps[0]); j++)
            cout << ps[i][j] << " \n"[j == sz(ps[0]) - 1];
  }

};
