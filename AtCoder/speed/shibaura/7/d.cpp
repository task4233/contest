#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

signed main() {
  int n,m;cin>>n>>m;
  vector<int> a(n),sm(n+1,0);
  map<int,int> mp;
  for(int i=0;i<n;++i) {
    cin>>a[i];
    a[i]%=m;
    (sm[i+1] += sm[i] + a[i]) %= m;
  }
  for(int i=0;i<n;++i){
    debug(sm[i+1]);
    ++mp[sm[i+1]];
  }

  int ans = 0;
  for(auto &&mi: mp){
    if(mi.first==0){
      ans += max((1+mi.second)*mi.second/2, 0LL);
    }else{
      ans += max((1+mi.second-1)*(mi.second-1)/2, 0LL);
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
