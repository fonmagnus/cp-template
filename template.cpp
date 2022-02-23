# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long

# define rep(i, n) for(int i=0; i<n; i++)
# define repi(i, n) for(int i=1; i<=n; i++)
# define each(x, v) for(auto x : v)

# define Int(a) int a; cin >> a;
# define String(a) string a; cin >> a;
# define Double(a) double a; cin >> a;
# define Arr(a, n) vector<int> a(n); for(int i=0; i<n; i++) cin >> a[i];

# define Tree(n) \
  int n; cin >> n; \
  vector<int> adj[n+1]; \
  for(int i=1; i<n; i++) { \
    int u, v; cin >> u >> v; \
    adj[u].push_back(v); adj[v].push_back(u); \
  }

template <typename T>
void print(T &v){
  each(x, v) { cout << x << " "; }
  cout << endl;
}

ll solve(){
  Tree(n);
  return 0;
}

signed main(){
  ios_base :: sync_with_stdio(false);
  Int(t);
  while(t--){
    ll ans = solve();
  }
}