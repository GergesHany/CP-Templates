template < typename T = int > struct Dijkstra{
 
  // Edge Structure
  struct Edge{
    T V, W;
    Edge(T v, T w) : V(v), W(w) {}
    bool operator < (const Edge &e) const { return W > e.W; }
  };
 
  // default constructor
  Dijkstra() = default;
 
  T n, m;
  vector < T > dist, par;
  vector < vector < Edge > > adj;
 
  // add edge
  void addEdge(T u, T v, T w, bool bidirectional = true){
    adj[u].push_back({v, w});
    if (bidirectional) adj[v].push_back({u, w});
  }
 
  // constructor to initialize the graph
  Dijkstra(T n, T m, bool dir = true) : n(n), m(m), adj(n + 1), dist(n + 1, INF), par(n + 1, -1) {
    for (T i = 0, u, v, w; i < m && cin >> u >> v >> w; ++i){
      addEdge(u, v, 2 * w, dir);
    }
  }
 
  // single source shortest path
  vector < T > shortestPath(T src){
    priority_queue < Edge > pq;
    pq.push({src, dist[src] = 0});
    while (!pq.empty()){
      Edge e = pq.top(); pq.pop();
      if (e.W > dist[e.V]) continue;
      for (Edge ne : adj[e.V]){
        if (dist[ne.V] > e.W + ne.W){
          dist[ne.V] = e.W + ne.W;
          par[ne.V] = e.V;
          pq.push({ne.V, dist[ne.V]});
        }
      }
    }
    return dist;
  }
 
  // multiple source shortest path
  vector < T > shortestPath(vector < T > src){
    priority_queue < Edge > pq;
    for (T i = 0; i < sz(src); ++i){
      pq.push({src[i], dist[src[i]] = 0});
    }
    while (!pq.empty()){
      Edge e = pq.top(); pq.pop();
      if (e.W > dist[e.V]) continue;
      for (Edge ne : adj[e.V]){
        if (dist[ne.V] > e.W + ne.W){
          dist[ne.V] = e.W + ne.W;
          par[ne.V] = e.V;
          pq.push({ne.V, dist[ne.V]});
        }
      }
    }
    return dist;
  }
 
  // shortest path from src to dest
  T shortestPath(T src, T dest){
    return shortestPath(src)[dest]; 
  }
 
  // path from src to dest
  vector < T > path(T src, T dest){
    shortestPath(src);
    vector < T > path;
    for (T i = dest; ~i; i = par[i]) path.push_back(i);
    reverse(all(path));
    return path;
  }
 
};
