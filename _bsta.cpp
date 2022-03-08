# include <bits/stdc++.h>
using namespace std;
# define int long long

bool ok(int x){
  // TODO : Change This according to check whether x is valid answer
  return true;
}

int bsta(int MIN, int MAX){
  int lo = MIN, hi = MAX;
  int ans = -1;
  while(lo <= hi){
    int mid = (lo + hi) / 2;
    // TODO : Change This according to behavior of answer
    if(ok(mid)){
      lo = mid+1; 
      ans = mid;
    }
    else hi = mid-1; 
  }
  return ans;
}

signed main(){
  ios_base :: sync_with_stdio(false);
}