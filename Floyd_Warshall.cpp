template < typename T = int > struct Floyd_Warshall{

  struct Edge{
    ll u, v, w;
    Edge(ll U = 0, ll V = 0, ll W = 0) : u(U), v(V), w(W) {}
    bool operator < (const Edge &other) const{
      return w < other.w;
    }
  };
 

  T n, m, INT = 1LL << 60;
  vector < Edge > edges;
  vector < vector < T > > dist;

  // default constructor
  Floyd_Warshall() = default;

  // constructor to initialize the graph
  Floyd_Warshall(T n, T m) : n(n), m(m), dist(n + 1, vector < T > (n + 1, INF)) {
    edges = vector < Edge > (m);
    for (auto &e : edges){
      cin >> e.u >> e.v >> e.w;
      dist[e.u][e.u] = dist[e.v][e.v] = 0; // if there is a self loop
      dist[e.u][e.v] = dist[e.v][e.u] = operation(dist[e.u][e.v], e.w, dist[e.v][e.u]);
    }
    Build();
  }

  T operation(T a, T b, T c){
    return min(a, b + c);
  }

  // function to build the shortest path
  void Build(){
    for (int i = 0; i <= n; ++i) dist[i][i] = 0;
    for (T k = 1; k <= n; ++k)
      for (T i = 1; i <= n; ++i)
        for (T j = 1; j <= n; ++j)
          dist[i][j] = operation(dist[i][j], dist[i][k], dist[k][j]);
  }
  
  // function to check if there is a negative cycle
  bool Transitive_Closure(T u, T v){
    return dist[u][v] < INF;
  }

  // function to get the shortest distance
  T Get_Distance(T u, T v){
    return dist[u][v];
  }

    // function to get the diameter of the graph
  T Get_Diameter(){
    T ans = 0;
    for (T i = 1; i <= n; ++i)
       for (T j = 1; j <= n; ++j) ans = max(ans, dist[i][j] == INF ? 0 : dist[i][j]);
    return ans;
  }
  
  // function to get the number of paths between two nodes
  T count_paths(T u, T v){
    if (dist[u][v] == INF) return 0;
    T ans = 0;
    for (T i = 1; i <= n; ++i)
      for (T j = 1; j <= n; ++j) ans += (dist[u][i] + dist[i][j] + dist[j][v] == dist[u][v]);
    return ans;
  }

  // function to check if there is a negative cycle
  bool Negative_Cycle(){
    for (T i = 1; i <= n; ++i) if (dist[i][i] < 0) return true;
    return false;
  }

  // function to check if there is a negative cycle between two nodes
  bool any_effective_cycle(T u, T v){
    for (T i = 1; i <= n; ++i) 
      if (dist[i][i] < 0 && dist[u][i] < INF && dist[i][v] < INF) return true;
    return false;
  }
  

};
