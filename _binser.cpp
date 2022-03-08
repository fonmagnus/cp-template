# include <bits/stdc++.h>
using namespace std;
# define int long long

// * finds a leftmost number in a list that is ≥ key
int lower(vector<int> &v, int key) {
  int lo = 0, hi = (int) v.size()-1;
  int res = -1;
  while(lo <= hi){
    int mid = (lo+hi) / 2;
    if(v[mid] >= key) {
      res = mid;
      hi = mid-1;
    }
    else lo = mid+1;
  }
  return res;
}

// * finds a rightmost number in a list that is ≤ key
int upper(vector<int> &v, int key){
  int lo = 0, hi = (int) v.size()-1;
  int res = -1;
  while(lo <= hi){
    int mid = (lo+hi) / 2;
    if(v[mid] <= key){
      res = mid;
      lo = mid+1;
    }
    else hi = mid-1;
  }
  return res;
}

signed main(){
  ios_base :: sync_with_stdio(false);
  
}