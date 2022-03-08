# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p2(int x) { return 1<<x; }
const int LOG = 17;
const int MAXN = 1e5;
int arr[MAXN+5], st[MAXN+5][LOG+1];
int n;

void build(int n){
  for(int d=1; d<LOG; d++){
    for(int i=0; i + p2(d) - 1 < n; i++){
      st[i][d] = min(st[i][d-1], st[i + p2(d-1)][d-1]);
    }
  }
}

int get(int l, int r){
  int len = log2(r-l+1);
  return min(st[l][len], st[r-p2(len)][len]);
}

int main(){
  ios_base :: sync_with_stdio(false);

  return 0;
}