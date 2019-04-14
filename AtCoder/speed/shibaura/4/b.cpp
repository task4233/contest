#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,k;
  cin>>n>>k;
  int ans = k;
  for(int i=0;i<n-1;++i) ans *= (k-1);
  cout<<ans<<endl;
  return 0;
}
