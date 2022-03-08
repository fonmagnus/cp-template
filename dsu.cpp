# include <bits/stdc++.h>
using namespace std;
# define int long long

const int MAXN = 2e5;
int par[MAXN + 5];
void init() { for(int i=1; i<=MAXN; i++) par[i] = i; }
int get(int x) { return (x==par[x] ? x : par[x] = get(par[x])); }
void merge(int u, int v) { par[get(u)] = get(v); }
bool same(int u, int v) { return get(u) == get(v); }

signed main(){
  ios_base :: sync_with_stdio(false);
  init();
}