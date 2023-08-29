#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
  
using namespace std; 
using namespace __gnu_pbds;
  
#define EPS 1e-8
#define sz(s) (int)(s.size())  
#define rall(s)  s.rbegin(), s.rend()
#define getline(s) getline(cin >> ws, s)
#define all(vec)  vec.begin(),  vec.end()
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define endd(s) return void(cout << s << "\n")
#define fixed(n) cout << fixed << setprecision(n)
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define ordered_set tree<ll, null_type, less <ll>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<ll, null_type, less_equal <ll>, rb_tree_tag,tree_order_statistics_node_update>
  
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = 1e9 + 7, INF = 1LL << 60, N = 3000 + 5;
  
void Gerges_Hany(){
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
  #endif
}
  
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
  for (auto &x : v) in >> x; return in;
}
  
template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
  for (const T &x : v) out << x << ' '; return out;
}


template < typename T = int, bool Mode = 0 > struct Binary_Heap {
  
    int size; 
    T DEFAULT;
    vector < T > heap; 
    
    void intial(int n){
        size = 0, DEFAULT = (Mode == 0 ? 1e9 : -1e9);
        heap = vector < T > (n + 1, DEFAULT);
    }
  
    Binary_Heap(int n){
        intial(n);
    }
  
    // Main operation to do
  
    bool operation(T a, T b){
        if(Mode == 0) return a < b; // Min Heap
        return a > b; // Max Heap
    }

    int left(int i){ return 2 * i; }
    int right(int i){ return 2 * i + 1; }
    int parent(int i){ return i / 2; }
  
    // Heapify (Fix Heap)

    void heapify(int i, int n){
        int l = left(i), r = right(i), mn = i;
        if(l <= n && operation(heap[l], heap[mn])) mn = l;
        if(r <= n && operation(heap[r], heap[mn])) mn = r;
        if(mn != i){
            swap(heap[i], heap[mn]);
            heapify(mn, n);
        }
    }
  
    // Build Heap (Heapify all nodes)
  
    void build_heap(){
        for(int i = size / 2; i >= 1; i--) heapify(i);
    }

   // Fix Heap (Fix one node)
    void Fix_Heap(int i){
        while(i > 1 && operation(heap[i], heap[parent(i)])){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
  
    // Insert (Add)
    void insert(T val){
        if(size == sz(heap) - 1) return void(cout << "Heap is Full\n");
        heap[++size] = val;
        Fix_Heap(size);
    }

   // Update (Change value)
    void update(int i, T val){
        if(i > size || i < 0) return void(cout << "Invalid Index\n");
        heap[i] = val;
        Fix_Heap(i);
    }
  
    // Extract (Remove)
    T extract(){
        if(size == 0) return DEFAULT;
        T val = heap[1];
        heap[1] = heap[size--];
        heapify(1);
        return val; // return the value of the removed node
    }
  
    // Top (Get the value of the top node)
    T top(){
      return (size == 0 ? DEFAULT : heap[1]);
    }
  
    // Size
    int Size(){ return size; }
  
    // Empty
    bool empty(){ return !size; }
  
    // Clear
    void clear(){ size = 0; }
  
    // Print
    void print(){
        for(int i = 1; i <= size; i++) cout << i << " - " << heap[i] << "\n";
    }
  
};

void Accepted(){
  
  int n;
  cin >> n;
  vector < int > vec(n);
  cin >> vec;

  Binary_Heap < ll, true > heap(n + 1);
  for (auto &i : vec) heap.insert(i);

  heap.print();
  cout << "\n";
  cout << heap.top() << "\n";
  heap.update(1, 100);
  cout << heap.top() << "\n";
  heap.insert(1000);
  cout << heap.top() << "\n";

}

int main()
{ 

  Gerges_Hany();
  int testcaces = 1, T = 1;
  // cin >> testcaces;
  while (testcaces--){
    // cout << "Case " << T++ << ": ";
    Accepted();
  }   
  Time;
  return 0;
}
