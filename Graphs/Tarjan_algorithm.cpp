template < typename T = int > struct Tarjan_algorithm{
 
  stack < T > st;
  T dfs_timer, num_scc;
  vector < T > dfs_num, dfs_low, vis, comp;
  vector < vector < T > > adj, components_graph, scc;

  // default constructor
  Tarjan_algorithm() = default;

  // constructor to initialize the number of nodes
  Tarjan_algorithm(T n){
    dfs_timer = num_scc = 0;
    adj = vector < vector < T > > (n + 1);
    dfs_num = dfs_low = vis = comp = vector < T > (n + 1);
  }
 
  // function to add edge
  void add_edge(T u, T v, bool undirected = false){
    adj[u].push_back(v);
    if (undirected) adj[v].push_back(u);
  }
 
  // function to run the algorithm
  void tarjan(T node){
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    st.push(node);
    vis[node] = true;
    for (auto child : adj[node]){
      if (!dfs_num[child]){
        tarjan(child);
        dfs_low[node] = min(dfs_low[node], dfs_low[child]);
      }else if (vis[child]){ // back edge (cycle)
        dfs_low[node] = min(dfs_low[node], dfs_num[child]);
      }
    }
 
    if (dfs_low[node] == dfs_num[node]){
      ++num_scc;
      scc.push_back(vector < T > ());
      while(true){
        T x = st.top();
        st.pop();
        vis[x] = false; // to avoid cycle in the same component 
        comp[x] = num_scc;
        scc.back().push_back(x);
        if (x == node) break;
      }
    }
  }
 
  // function to run the algorithm on all nodes
  void solve(){
    for (T i = 1; i < sz(adj); ++i) if (!dfs_num[i])  tarjan(i);
  }
 
  void print(){
    cout << num_scc << "\n";
    for (T i = 1; i < sz(adj); ++i){
      cout << i << " " << comp[i] << "\n";
    }
  }

  // function to get the number of SCC 
  T get_num_scc(){
    return num_scc;
  }
 
  // function to get the component of each node
  vector < T > get_comp(){
    return comp;
  }
  
  // function to get the SCC graph
  vector < vector < T > > SCC(){
    return scc;
  }

  // function to check if u is an ancestor of v
  bool is_ancestor(T u, T v){
    return (dfs_num[u] <= dfs_num[v] && dfs_low[u] >= dfs_low[v]);
  }
 
};
