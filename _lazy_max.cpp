# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MAXN = 1e5;

int n;
int node[MAXN*4 + 5], lazy[MAXN*4 + 5];
int arr[MAXN+5];

void push(int id){
  int lc = 2*id, rc = 2*id+1;
  node[lc] += lazy[id]; 
  lazy[lc] += lazy[id];
  node[rc] += lazy[id];
  lazy[rc] += lazy[id];
  lazy[id] = 0;
}

void build(int l, int r, int id){
  if(l == r) {
    node[id] = arr[l];
    return;
  }
  int m = (l+r)/2;
  build(l, m, 2*id);
  build(m+1, r, 2*id+1);
  node[id] = max(node[2*id], node[2*id+1]);
}

void update(int l, int r, int id, int from, int to, int val){
  if(from > to) return;
  if(l == from && to == r) {
    lazy[id] += val;
    node[id] += val;
    return;
  }
  push(id);
  int m = (l+r)/2;
  update(l, m, 2*id, from, min(to, m), val);
  update(m+1, r, 2*id+1, max(m+1, from), to, val);
  node[id] = max(node[2*id], node[2*id+1]);
}

int get(int l, int r, int id, int from, int to){
  if(l == r) return node[id];
  if(to < l || r < from) return 0;
  else if(from <= l && r <= to) return node[id];
  push(id);
  int m = (l+r)/2;
  return max(
    get(l, m, 2*id, from, to),
    get(m+1, r, 2*id+1, from, to)
  );
}

signed main(){
  ios_base :: sync_with_stdio(false);
  cin >> n;
  for(int i=1; i<=n; i++){
    int x; cin >> x;
    update(1, n, 1, i, i, x);
  }

  int q;
  cin >> q;
  while(q--){
    int t; cin >> t;
    if(t == 1) {
      int l, r, x; cin >> l >> r >> x;
      update(1, n, 1, l, r, x);
    }
    else {
      int l, r; cin >> l >> r;
      cout << get(1, n, 1, l, r) << endl;
    }
  }
}