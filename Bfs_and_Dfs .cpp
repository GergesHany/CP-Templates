template < typename T = int > struct Graph{

  T n, m, cc;
  vector < bool > vis;
  vector < vector < T > > adj;
  vector < T > depth, parent, deg, colour;
  
  Graph(T n): n(n), adj(n), vis(n), depth(n), parent(n), deg(n), colour(n) {}
  
  void addEdge(T u, T v, bool directed = false){
    adj[u].push_back(v);
    if(!directed) adj[v].push_back(u);
  }

  void removeEdge(T u, T v, bool directed = false){
    auto it1 = find(all(adj[u]), v);
    if(it1 != adj[u].end()) adj[u].erase(it1), deg[u]--;
    if(!directed){
      auto it2 = find(all(adj[v]), u);
      if(it2 != adj[v].end()) adj[v].erase(it2), deg[v]--;
    }
  }

  void dfs(T node, T dep = 0, T par = -1){
    vis[node] = true, depth[node] = dep, parent[node] = par; 
    for(auto child : adj[node]){
      if(!vis[child]){
        dfs(child, depth + 1, node);
      }
    }
  }
  
  void path(T node){
    if(node == -1) return;
    path(parent[node]);
    cout << node << " ";
  }

  bool isCyclic(T node, T par = -1){
    vis[node] = true;
    for(auto child : adj[node]){
      if(!vis[child]){
        if(isCyclic(child, node)) return true;
      }else if(child != par) return true;
    }
    return false;
  }

  bool is_Bipartite(T node, T col = 0){
    vis[node] = true, colour[node] = col;
    for(auto child : adj[node]){
      if(!vis[child]){
        if(is_Bipartite(child, col ^ 1)) return true;
      }else if(colour[child] == colour[node]) return true;
    }
    return false;
  }

  bool is_Bipartite(){
    for(T i = 0; i < n; i++)
      if(!vis[i] && is_Bipartite(i)) return false;
    return true;
  }

  T connectedComponents(){
    for(T i = 0; i < n; i++)
      if(!vis[i])
        dfs(i), cc++;
    return cc;
  }
  
  void topologicalSort(){
    vector < T > indeg(n);
    for(T i = 0; i < n; i++)
      for(auto child : adj[i])
        indeg[child]++;
    queue < T > q;
    for(T i = 0; i < n; i++)
      if(!indeg[i])
        q.push(i);
    while(!q.empty()){
      T node = q.front();
      q.pop();
      cout << node << " ";
      for(auto child : adj[node]){
        indeg[child]--;
        if(!indeg[child])
          q.push(child);
      }
    }
  }
  
  T Bfs(T from, T to){
    queue < T > q;
    q.push(from);
    while(!q.empty()){
      T node = q.front();
      q.pop();
      if(node == to) return depth[node];
      for(auto child : adj[node]){
        if(!vis[child]){
          vis[child] = true;
          depth[child] = depth[node] + 1;
          q.push(child);
        }
      }
    }
    return -1;
  }

};

