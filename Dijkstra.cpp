template < typename T = int > struct Dijkstra{
 
 
  struct Edge{
    T V, W;
    Edge(T v, T w) : V(v), W(w) {}
    bool operator < (const Edge &e) const { return W > e.W; }
  };
 
  T n, m;
  vector < T > dist, par;
  vector < vector < Edge > > adj;
 
  void addEdge(T u, T v, T w, bool bidirectional = true){
    adj[u].push_back({v, w});
    if (bidirectional) adj[v].push_back({u, w});
  }
 
  Dijkstra(T n, T m, bool dir = true) : n(n), m(m), adj(n + 1), dist(n + 1, INF), par(n + 1, -1) {
    for (T i = 0, u, v, w; i < m && cin >> u >> v >> w; ++i){
      addEdge(u, v, w, dir);
    }
  }
 
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
 
  T shortestPath(T src, T dest){
    return shortestPath(src)[dest]; 
  }
 
  vector < T > path(T src, T dest){
    shortestPath(src);
    vector < T > path;
    for (T i = dest; i != -1; i = par[i]) path.push_back(i);
    reverse(all(path));
    return path;
  }
 
};
