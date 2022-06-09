# include <bits/stdc++.h>
using namespace std;
# define int long long
const int mod = 1e9 + 7;
const int maxn = 2e5;

int add(int a, int b) { return (a+b) % mod; }
int sub(int a, int b) { return (a-b+mod) % mod; }
int mul(int a, int b) { return (a*b) % mod; }
int pw(int a, int b){
  if(b == 0) return 1;
  int t = pw(a, b/2);
  if(b%2 == 0) return mul(t, t);
  return mul(a, mul(t,t));
}

int f[maxn+5], fi[maxn+5];
void precompute(){
  f[0] = 1;
  for(int i=1; i<=maxn; i++) f[i] = mul(f[i-1], i);
  fi[maxn] = pw(f[maxn], mod-2);
  for(int i=maxn-1; i>=0; i--) fi[i] = mul(fi[i+1], i+1);
}
int C(int n, int k) { return n < k ? 0 : mul(f[n], mul(fi[n-k], fi[k])); }

signed main(){
  ios_base :: sync_with_stdio(false);
  precompute();
}