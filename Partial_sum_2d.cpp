template < typename T = long long > struct Partial_sum_2d{

  T n, m;
  T x1, y1, x2, y2, val = 1;
  vector < vector < T > > Partial;
  Partial_sum_2d(T n, T m){
    this -> n = n, this -> m = m;
    Partial.assign(n + 5, vector < T > (m + 5, 0));
  }

  void scan_Partial(T x1, T y1, T x2, T y2, T val){
    this -> x1 = x1, this -> y1 = y1, this -> x2 = x2, this -> y2 = y2, this -> val = val;
  }

  void build_Partial(T queries){
    while(queries--){
      Partial[x2][y2] += val, Partial[x2][y1 - 1] -= val;
      Partial[x1 - 1][y2] -= val, Partial[x1 - 1][y1 - 1] += val;
    }
  
    for (int i = n; i >= 0; i--)
      for (int j = m; j >= 0; j--)
        Partial[i][j] += Partial[i][j + 1];
    
    for (int i = n; i >= 0; i--)
      for (int j = m; j >= 0; j--)
        Partial[i][j] += Partial[i + 1][j];
  }

  T get_Partial(T x, T y){
    return Partial[x][y];
  }

  void print(){
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        cout << Partial[i][j] << " \n"[j == m];
  }

};