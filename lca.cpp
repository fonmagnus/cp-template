#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int LOG = 17;
 
vector<int> adj[MAXN + 5];
int depth[MAXN + 5];
int up[MAXN+5][LOG];
 
void dfs(int u){
  for(int v : adj[u]){
    depth[v] = depth[u] + 1;
    up[v][0] = u;
    for(int i = 1; i < LOG; i++){
      up[v][i] = up[up[v][i-1]][i-1];
    }
    dfs(v);
  }
}
 
int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);
  int d = depth[u] - depth[v];
  for(int i=LOG-1; i>=0; i--){
    if((d >> i) & 1)
      u = up[u][i];
  }
  if(u == v) return u;
  for(int i=LOG-1; i>=0; i--){
    if(up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int main() {
  ios_base :: sync_with_stdio(false);
  
}  