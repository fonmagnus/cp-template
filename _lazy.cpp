# include <bits/stdc++.h>
using namespace std;
# define int long long
const int RMINQ = 0;
const int RMAXQ = 1;
const int RSQ = 2;

const int MAXN = 1e5;
const int MODE = RMINQ;

int node[MAXN*4 + 5], lazy[MAXN*4 + 5];
int arr[MAXN+5];

int merge(int a, int b){
  if(MODE == RMINQ) return min(a, b);
  else if(MODE == RMAXQ) return max(a, b);
  else if(MODE == RSQ) return a+b;
  else {
    // * CUSTOM MERGE
    return a+b;
  }
}

int base(){
  if(MODE == RMINQ) return 1e15;
  else if(MODE == RMAXQ) return -1e15;
  else if(MODE == RSQ) return 0;
  else {
    // * CUSTOM MODE
    return 0;
  }
}

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
  node[id] = merge(node[2*id], node[2*id+1]);
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
  node[id] = merge(node[2*id], node[2*id+1]);
}

int get(int l, int r, int id, int from, int to){
  if(l == r) return node[id];
  if(to < l || r < from) return base();
  else if(from <= l && r <= to) return node[id];
  push(id);
  int m = (l+r)/2;
  return merge(
    get(l, m, 2*id, from, to),
    get(m+1, r, 2*id+1, from, to)
  );
}

signed main(){
  ios_base :: sync_with_stdio(false);
  
}