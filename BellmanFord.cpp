template < typename T = int > struct BellmanFord{
 
  // Edge Structure
  struct Edge{
    T U, V, W;
    Edge(T u, T v, T w) : U(u), V(v), W(w) {}
  };
 
  // default constructor
  BellmanFord() = default;
 
  bool WasProcessed = false;
  T n, m, INF = 1LL << 60;
  vector < T > dist, par;
  vector < Edge > edges;
 
  // add edge
  void addEdge(T u, T v, T w, bool bidirectional = true){
    edges.push_back({u, v, w});
    if (bidirectional) edges.push_back({v, u, w});
  }
 
  // constructor to initialize the graph
  BellmanFord(T n, T m, bool dir = true) : n(n), m(m), dist(n + 1, INF), par(n + 1, -1) {
    for (T i = 0, u, v, w; i < m && cin >> u >> v >> w; ++i){
      addEdge(u, v, w, dir);
    }
  }

  // return shortest path from source to all nodes
  vector < T > shortestPath(T source){
    dist[source] = 0;
    WasProcessed = true;
    bool updated = false;
    for (T i = 0; i < n - 1; ++i){
      for (auto &e : edges){
        if (dist[e.U] + e.W < dist[e.V]){
          dist[e.V] = dist[e.U] + e.W;
          par[e.V] = e.U;
          updated = true;
        }
      }
      if (!updated) break;
    }
    return dist;
  }

  // return shortest path from source to target
  T shortestPath(T source, T target){
    return shortestPath(source)[target];
  }

  // return true if there is a negative cycle
  bool negativeCycle(){
    if (!WasProcessed) shortestPath(1);
    for (auto &e : edges)
      if (dist[e.U] + e.W < dist[e.V])
        return true;
    return false;
  }

  // return true if there is a negative cycle in the path from source to target
  // return true if there is a negative cycle in the path from source to target
  bool negativeCycle(T source, T target){
    if (!WasProcessed) shortestPath(source);
    vector < T > temp = dist;
    for (auto &e : edges)
      if (temp[e.U] + e.W < temp[e.V])
        temp[e.V] = temp[e.U] + e.W;
    return temp[target] < dist[target];
  }

  // return the path from source to target
  vector < T > path(T source, T target){
    if (!WasProcessed) shortestPath(source);
    vector < T > path;
    for (T i = target; i != -1; i = par[i])
      path.push_back(i);
    reverse(all(path));
    return path;
  }
 
 
};
