# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

#define lsone(x) x&(-x)
struct Node {
  int data, id;
  Node(int d=0, int i=0){
    data = d;
    id = i;
  }

  inline friend bool operator < (const Node &a, const Node &b){
    return a.id < b.id;
  }
};

const int maxn = 200005;
int now; // * time tracker
vector<Node> tree[maxn + 5];
inline void init(){
  now = 0;
  for(int i=1; i<=maxn; i++){
    tree[i].clear();
    tree[i].push_back(Node());
  }
}

inline void update(int x, int d){
  now++;
  for(int i=x; i<=maxn; i += lsone(i))
    tree[i].push_back(Node(tree[i].back().data + d, now));
}

inline int get(int x, int id){
  int ans = 0;
  for(int i=x; i>0; i -= lsone(i)){
    auto a = upper_bound(tree[i].begin(),tree[i].end(), Node(0, id))-1;
    ans += a->data;
  }
  return ans;
}

int get(int l, int r, int id){
  return get(r, id) - get(l-1, id);
}

signed main(){
  ios_base :: sync_with_stdio(false); 
  init();
}