# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)
const int maxn = 300000;
int node[4*maxn + 5], lazy[4*maxn + 5];
int n, k;

void push(int id, int l, int r){
  int lc = 2*id, rc = 2*id+1;
  int m = (l+r)/2;
  
  node[lc] += (m-l+1) * lazy[id];
  lazy[lc] += lazy[id];

  node[rc] += (r-m) * lazy[id];
  lazy[rc] += lazy[id];

  lazy[id] = 0;
}

void update(int from, int to, int val, int l = 1, int r = n, int id = 1){
  if(from > to) return;
  if(from == l && to == r){
    node[id] += (r-l+1) * val;
    lazy[id] += val;
    return;
  }
  int m = (l+r)/2;
  push(id, l, r);
  update(from, min(to, m), val, l, m, 2*id);
  update(max(from, m+1), to, val, m+1, r, 2*id+1);
  node[id] = node[2*id] + node[2*id+1];
}

int get(int from, int to, int l = 1, int r = n, int id = 1){
  if(l > to || r < from) return 0;
  if(from <= l && r <= to) return node[id];
  int m = (l+r)/2;
  push(id, l, r);
  return get(from, to, l, m, 2*id) + get(from, to, m+1, r, 2*id+1);
}

int solve(){
  
  return 0;
}

signed main(){
  ios_base :: sync_with_stdio(false);
  int t = 1;
  while(t--){
    int ans = solve();
  }
}