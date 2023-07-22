# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

signed main(){
  ios_base :: sync_with_stdio(false); 
  int n; cin >> n;
  int a[n+1];
  for(int i=1; i<=n; i++){
    cin >> a[i];
  }

  int l[n+1], r[n+1];
  for(int i=1; i<=n; i++){
    l[i] = 0;
    r[i] = n+1;
  }

  vector<int> stack;
  for(int i=1; i<=n; i++){
    while(!stack.empty() && a[stack.back()] < a[i]){
      r[stack.back()] = i;
      stack.pop_back();
    }
    stack.push_back(i);
  }
 
  stack.clear();
  for(int i=n; i>=1; i--){
    while(!stack.empty() && a[stack.back()] < a[i]){
      l[stack.back()] = i;
      stack.pop_back();
    }
    stack.push_back(i);
  }

  // * after this part : 
  // * l[i] : index of next greater element in the left side of i
  // * r[i] : index of next greater element in the right side of i
}