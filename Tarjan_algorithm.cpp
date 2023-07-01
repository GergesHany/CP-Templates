template < typename T = int > struct Tarjan_algorithm{
 
  stack < T > st;
  T dfs_timer, num_scc;
  vector < T > dfs_num, dfs_low, vis, comp;
  vector < vector < T > > adj, components_graph, scc;
 
  Tarjan_algorithm(T n){
    dfs_timer = num_scc = 0;
    adj = vector < vector < T > > (n + 1);
    dfs_num = dfs_low = vis = comp = vector < T > (n + 1);
  }
 
  void add_edge(T u, T v, bool undirected = false){
    adj[u].push_back(v);
    if (undirected) adj[v].push_back(u);
  }
 
  void tarjan(T node){
    dfs_num[node] = dfs_low[node] = ++dfs_timer;
    st.push(node);
    vis[node] = true;
    for (auto child : adj[node]){
      if (!dfs_num[child]){
        tarjan(child);
        dfs_low[node] = min(dfs_low[node], dfs_low[child]);
      }else if (vis[child]){
        dfs_low[node] = min(dfs_low[node], dfs_num[child]);
      }
    }
 
    if (dfs_low[node] == dfs_num[node]){
      ++num_scc;
      scc.push_back(vector < T > ());
      while(true){
        T x = st.top();
        st.pop();
        vis[x] = false;
        comp[x] = num_scc;
        scc.back().push_back(x);
        if (x == node) break;
      }
    }
  }
 
  void solve(){
    for (T i = 1; i < sz(adj); ++i) if (!dfs_num[i])  tarjan(i);
  }
 
  void print(){
    cout << num_scc << "\n";
    for (T i = 1; i < sz(adj); ++i){
      cout << i << " " << comp[i] << "\n";
    }
  }
 
  T get_num_scc(){
    return num_scc;
  }
 
  vector < T > get_comp(){
    return comp;
  }
  
  vector < vector < T > > SCC(){
    return scc;
  }
 
};