#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
const int LOG = 11;
int dp[MAXN+5][MAXN+5];
int st[MAXN+5][LOG][MAXN+5][LOG];

int p2(int d) { return 1<<d; }

void build(int R, int C){
  for(int i=1; i<=R; i++){
    for(int j=1; j<=C; j++){
      int x; scanf("%d", &x);
      st[i][0][j][0] = x;
    }

    for(int dj=1; dj<LOG; dj++){
      for(int j=1; j+p2(dj)-1 <= C; j++){
        st[i][0][j][dj] = min(st[i][0][j][dj-1], st[i][0][j+p2(dj-1)][dj-1]);
      }
    }
  }  

  for(int di=1; di<LOG; di++){
    for(int i=1; i+p2(di)-1 <= R; i++){
      for(int dj=0; dj<LOG; dj++){
        for(int j=1; j+p2(dj)-1 <= C; j++){
          st[i][di][j][dj] = min(
            st[i][di-1][j][dj],
            st[i+p2(di-1)][di-1][j][dj]
          );
        }
      }
    }
  }
}

int get(int t, int l, int b, int r){
  int h = log2(b-t+1);
  int w = log2(r-l+1);
  
  int tl = st[t][h][l][w];
  int tr = st[t][h][r-p2(w)+1][w];
  int bl = st[b-p2(h)+1][h][l][w];
  int br = st[b-p2(h)+1][h][r-p2(w)+1][w];
  return min(min(tl, tr), min(bl, br));
}

int main() {
  ios_base :: sync_with_stdio(false);
} 