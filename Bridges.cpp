// Bridges is a node that if removed, the graph will be disconnected.
template < typename T = int > struct Bridges{

  T dfs_timer;
  vector < vector < T > > adj;
  vector < pair < T, T > > bridges;
  vector < T > dfs_num, dfs_low, vis;

  // default constructor
  Bridges() = default;

  // constructor to initialize the graph
  Bridges(T n){
    dfs_timer = 0;
    adj = vector < vector < T > > (n + 1);
    dfs_num = dfs_low = vis = vector < T > (n + 1);
  }

  // add edge to the graph
  void add_edge(T u, T v, bool bidirectional = true){
    adj[u].push_back(v);
    if (bidirectional) adj[v].push_back(u);
  }

  // tarjan algorithm to find bridges
  void tarjan(T node, T parent){
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    vis[node] = true;
    for (auto child : adj[node]){
      if (child == parent) continue;
      if (!dfs_num[child]){
        tarjan(child, node);
        dfs_low[node] = min(dfs_low[node], dfs_low[child]);
        if (dfs_low[child] > dfs_num[node]){ // bridge found
          bridges.push_back({node, child});
        }
      }else if (vis[child]){
        dfs_low[node] = min(dfs_low[node], dfs_num[child]);
      }
    }
  }

  void solve(){
    for (T i = 1; i < sz(adj); ++i) if (!dfs_num[i]) tarjan(i, -1);
  }
 
  // print the bridges
  void print(){
    cout << sz(bridges) << "\n";
    for (auto &x : bridges){
      cout << x.first << " " << x.second << "\n";
    }
  }

  // return the bridges
  vector < pair < T, T > > get_bridges(){
    return bridges;
  }

};
