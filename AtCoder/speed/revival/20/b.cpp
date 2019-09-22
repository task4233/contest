#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

int cnt(int id, vector<int> c){
  int res = 0;

  map<int,int> mp;
  for(int i=id; i<c.size(); ++i){
    
  }
  
  return res;
}

signed main() {
  int n;cin>>n;
  vector<int> c(n);
  for(int i=0;i<n;++i) cin>>c[i];

  int ans = 1 + cnt(0, c);
  
  map<int,int> mp;
  for(int i=0;i<n;++i){
    if(i>0 && c[i]==c[i-1]) continue;
    mp[c[i]]++;
  }

  int ans = 1 + cnt(0, mp);
  for(int i=0;i<n;++i){
    (ans += mi.second * (mi.second-1) / 2) %= (int)1e9+7;
  }
  cout<<ans<<endl;

  
  return 0;
}
