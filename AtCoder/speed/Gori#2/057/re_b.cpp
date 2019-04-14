#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int a,b;cin>>a>>b;
  int diff=abs(a-b);
  int ans = diff/10;
  diff -= ans*10;
  if(diff<3) ans += diff;
  else if(diff<8) ans += abs(5-diff)+1;
  else ans += (10-diff) + 1;

  cout<<ans<<endl;
  return 0;
}
