# include <bits/stdc++.h>
using namespace std;
# define int long long
const int MOD = 1e9 + 7;
const int MAXN = 2e5;

int add(int a, int b, int mod = MOD) { return (a+b) % mod; }
int sub(int a, int b, int mod = MOD) { return (a-b+mod) % mod; }
int mul(int a, int b, int mod = MOD) { return (a*b) % mod; }
int pw(int a, int b, int mod = MOD){
  if(b == 0) return 1;
  int t = pw(a, b/2, mod);
  if(b%2 == 0) return mul(t, t, mod);
  return mul(a, mul(t,t,mod), mod);
}

int f[MAXN+5], fi[MAXN+5];
void precompute(){
  f[0] = 1;
  for(int i=1; i<=MAXN; i++) f[i] = mul(f[i-1], i);
  fi[MAXN] = pw(f[MAXN], MOD-2);
  for(int i=MAXN-1; i>=0; i--) fi[i] = mul(fi[i+1], i+1);
}
int C(int n, int k) { return n > k ? 0 : mul(f[n], mul(fi[n-k], fi[k])); }

signed main(){
  ios_base :: sync_with_stdio(false);
  precompute();
}