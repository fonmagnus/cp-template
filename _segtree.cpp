# include <bits/stdc++.h>
using namespace std;
# define int long long
const int RMINQ = 0;
const int RMAXQ = 1;
const int RSQ = 2;

const int MAXN = 200000;
const int MODE = RMINQ;

int node[MAXN*4 + 5];
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

void update(int l, int r, int id, int pos, int val){
  if(l == r) {
    node[id] = arr[l] = val;
    return;
  }
  int m = (l+r)/2;
  if(pos <= m) update(l, m, 2*id, pos, val);
  else update(m+1, r, 2*id+1, pos, val);
  node[id] = merge(node[2*id], node[2*id+1]);
}

int get(int l, int r, int id, int from, int to){
  if(to < l || r < from) return base();
  else if(from <= l && r <= to) return node[id];
  int m = (l+r)/2;
  return merge(
    get(l, m, 2*id, from, to),
    get(m+1, r, 2*id+1, from, to)
  );
}

signed main(){
  ios_base :: sync_with_stdio(false);
}