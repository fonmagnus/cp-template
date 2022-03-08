#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
const int LOG = 17;

vector<int> adj[MAXN + 5];
int n;
int up[MAXN+5][LOG], depth[MAXN+5], sum[MAXN+5];

void dfs(int u, int p, int d){
  depth[u] = d;
  sum[u] = 1;
  for(int v : adj[u]){
    if(v == p) continue;
    up[v][0] = u;
    for(int i=1; i<LOG; i++){
      up[v][i] = up[up[v][i-1]][i-1];
    }
    dfs(v, u, d+1);
    sum[u] += sum[v];
  }
}

int binaryLifting(int u, int d){
  for(int i=LOG-1; i>=0; i--){
    if((d >> i) & 1)
      u = up[u][i];
  }
  return u;
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);

  int d = depth[u] - depth[v];
  u = binaryLifting(u, d);
  if(u == v) return u;
  for(int i=LOG-1; i>=0; i--){
    if(up[u][i] != up[v][i]){
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int dist(int u, int v){
  return depth[u] + depth[v] - 2*depth[lca(u, v)];
}

int main(){
  ios_base :: sync_with_stdio(false);
}