template < typename T = int > struct DSU{

  vector < T > parent, GroupSize;

  DSU(T n = 0){
    parent = vector < T > (n + 1);
    GroupSize = vector < T > (n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  T Find_leader(T node) {
    return parent[node] = (node == parent[node] ? node : Find_leader(parent[node]));
  }

  void Union(T node1, T node2) {
    node1 = Find_leader(node1), node2 = Find_leader(node2);
    if (node1 == node2) return;
    if (GroupSize[node1] < GroupSize[node2]) 
      swap(node1, node2);
    parent[node2] = node1;
    GroupSize[node1] += GroupSize[node2];
  }

  bool SameGroup(T node1, T node2) {
    return Find_leader(node1) == Find_leader(node2);
  }
  
  T SizeOfGroup(T node) {
    return GroupSize[Find_leader(node)];
  }

};
