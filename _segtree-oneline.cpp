# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

const int MAXN = 1e7;
class Segtree {
  // ! use zero base indexing
  private:
    int N = MAXN;
    vector<int> stree;

  public:
    Segtree(int N){
      this->N = N;
      stree.reserve(2*N);
    }

    // override this method
    int merge(int cl, int cr){
      return max(cl, cr);
    }
    
    void update(int pos, int val){
      for(stree[pos += N] = val; pos > 1; pos >>= 1){
        stree[pos>>1] = merge(stree[pos], stree[pos^1]);
      }
    }

    // ! query range [l, r] (inclusive, 0 based)
    int get(int l, int r){
      r++;
      int resl = 0, resr = 0;
      for(l += N, r += N; l < r; l >>= 1, r >>= 1){
        if(l&1) resl = merge(resl, stree[l++]);
        if(r&1) resr = merge(resr, stree[--r]);
      }
      return merge(resl, resr);
    }

    void build(vector<int> &v){
      for(int i=0; i<N; i++) stree[i+N] = v[i];
      for(int i=N-1; i>=0; i--) stree[i] = merge(stree[i<<1], stree[i<<1|1]);
    }
};

signed main(){
  ios_base :: sync_with_stdio(false); 
}