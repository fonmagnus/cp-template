# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

const int MAXN = 2e5;
const int LOG = 18;
int n;
vector<int> g[MAXN + 5];
ll st[4*MAXN+5];
int p[MAXN+5], dep[MAXN+5], nodeVal[MAXN+5];
int sz[MAXN+5], id[MAXN+5], tp[MAXN+5];

void update(int idx, ll val){
  st[idx += n] = val;
  for(idx/=2; idx; idx/=2) st[idx] = st[2*idx]+st[2*idx+1];
}

ll query(int lo, int hi) {
	ll ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = ra + st[lo++];
		if (hi & 1) rb = rb + st[--hi];
	}
	return ra+rb;
}

int dfs(int u, int par = 0){
  sz[u] = 1;
  p[u] = par;
  for(auto v: g[u]){
    if(v == par) continue;
    dep[v] = dep[u] + 1;
    p[v] = u;
    sz[u] += dfs(v, u);
  }
  return sz[u];
}

int cnt = 1;
void hld(int u, int par, int t){
  id[u] = cnt++;
  tp[u] = t;
  update(id[u], nodeVal[u]);

  int hchi = -1, hsz = -1;
  for(int v: g[u]){
    if(v == par) continue;
    if(sz[v] > hsz){
      hsz = sz[v];
      hchi = v;
    }
  }

  if(hchi == -1) return;
  hld(hchi, u, t);
  for(int v: g[u]){
    if(v == par || v == hchi) continue;
    hld(v, u, v);
  }
}

ll path(int u, int v){
  ll res = 0;
  while(tp[u] != tp[v]){
    if(dep[tp[u]] < dep[tp[v]]) swap(u, v);
    res += query(id[tp[u]], id[u]);
    u = p[tp[u]];
  }

  if(dep[u] > dep[v]) swap(u, v);
  res += query(id[u], id[v]);
  return res;
}


signed main(){
  ios_base :: sync_with_stdio(false); 
  cin >> n;
  for(int i=1; i<=n; i++) cin >> nodeVal[i];
  for(int i=1; i<n; i++){
    int u, v, weight; cin >> u >> v >> weight;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  hld(1, 1, 1);

  int q; cin >> q;
  while(q--){
    int t; cin >> t;
    if(t == 1){
      int u, val; cin >> u >> val;
      nodeVal[u] = val;
      update(id[u], val);
    }
    else if(t == 2){
      int u, v; cin >> u >> v;
      cout << path(u, v) << endl;
    }
  }
}