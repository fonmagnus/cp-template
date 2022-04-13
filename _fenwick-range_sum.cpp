# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

const int maxn = 300000;
int n, k;
int bit1[maxn + 5], bit2[maxn + 5];
int lsone(int x) { return x&(-x); }

void update(int bit[], int x, int val){
  for(int i=x; i<=n; i+=lsone(i))
    bit[i] += val;
}

void update(int l, int r, int val){
  update(bit1, l, val);
  update(bit1, r+1, -val);
  update(bit2, l, val*(l-1));
  update(bit2, r+1, -val*r);
}

int get(int bit[], int x){
  int res = 0;
  for(int i=x; i>0; i-=lsone(i))
    res += bit[i];
  return res;
}

int get(int x){
  return get(bit1, x)*x - get(bit2, x);
}

int get(int l, int r){
  return get(r) - get(l-1);
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