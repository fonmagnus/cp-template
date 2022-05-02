# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

int R, C, Q;
int bit[1005][1005];
bool mat[1005][1005];

void update(int r, int c, int val){
  for(int nr = r; nr <= R; nr += (nr & -nr)){
    for(int nc = c; nc <= C; nc += (nc & -nc)){
      bit[nr][nc] += val;
    }
  }
}

int get(int r, int c){
  int res = 0;
  for(int nr = r; nr > 0; nr -= (nr&-nr)){
    for(int nc = c; nc > 0; nc -= (nc&-nc)){
      res += bit[nr][nc];
    }
  }
  return res;
}

int get(int t, int l, int b, int r){
  return get(b, r) - get(t-1, r) - get(b, l-1) + get(t-1, l-1);
}

signed main(){
  ios_base :: sync_with_stdio(false);
  cin >> R >> C;
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      cin >> mat[i][j];
      update(i, j, mat[i][j]);
    }
  }
}