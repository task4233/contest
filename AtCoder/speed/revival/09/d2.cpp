#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<(x)<<endl;

int f(int n){
  if (n<=0) return 0;
  int res = 0;

  for(int digit=1;digit<50;++digit){
    int base = (1LL<<digit);
    int cnt = (n/base) * (base/2);
    cnt += max(0LL, (n%base) - (base/2) + 1);

    if (cnt%2 == 1) {
      res += (1LL << (digit-1));
    }
    debug(digit);
    debug(cnt);
    debug(res);
  }
  
  return res;
}

signed main() {
  int a,b;cin>>a>>b;
  int ans = f(b)^f(a-1);
  cout<<ans<<endl;
  
  return 0;
}
