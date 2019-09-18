#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int x,a,b,n;cin>>x>>a>>b>>n;
  int ans = x;
  for(int i=0;i<n;++i) {
    string s;cin>>s;
    if (s == "nobiro") ans += a;
    if (s == "tidime") ans += b;
    if (s == "karero") ans = 0;
    ans = max(ans, 0LL);
  }
  cout<<ans<<endl;
  return 0;
}
