# include <bits/stdc++.h>
using namespace std;
# define int long long
const int mod = 1e9 + 7;
const int maxn = 2e5;

int add(int a, int b) { return (a+b) % mod; }
int sub(int a, int b) { return (a-b+mod) % mod; }
int mul(int a, int b) { return ((a%mod)*(b%mod)) % mod; }
int pw(int a, int b){
  if(b == 0) return 1;
  int t = pw(a, b/2);
  if(b%2 == 0) return mul(t, t);
  return mul(a, mul(t,t));
}

signed main(){
  ios_base :: sync_with_stdio(false);
}