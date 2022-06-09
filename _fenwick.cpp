# include <bits/stdc++.h>
using namespace std;
# define int long long

const int maxn = 1e5;
int bit[maxn+5];
int ls(int x) { return x & (-x); }

void upd(int x, int val){
  for(int i=x; i<=maxn; i+=ls(i)) bit[i] += val;
}

int get(int x){
  int res = 0;
  for(int i=x; i>0; i-=ls(i)) res += bit[i];
  return res;
}

int get(int l, int r){
  return get(r) - get(l-1);
}

signed main(){
  ios_base :: sync_with_stdio(false);
}