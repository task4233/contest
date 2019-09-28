#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

signed main() {
  INIT;
  int n,k;cin>>n>>k;
  int ans = 0;
  for(int i=0;i<n;++i) {
    int p;cin>>p;
    if(p>=k) ++ans;
  }
  cout<<ans <<endl;
  return 0;
}
