#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n;cin>>n;
  vector<int> d(n);
  for(int i=0;i<n;++i) cin>>d[i];
  d.push_back(0);
  ++n;
  
  int ans = 0;
  for(int bit=0;bit<(1<<n);++bit){
    for(int i=0;i<n;++i){
      vector<int> p(d);
      if ((bit>>i) & 1) {
        d[i] = 24 - d[i];
      }
      
      int tmp = 1e9+1;
      for(int j=0;j<n;++j){
        for(int k=0;k<j;++k){
          tmp = min(abs(p[j]-p[k]), tmp);
        }
      }

      if (tmp<24) ans = max(ans, tmp);
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
