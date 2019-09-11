#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<(x)<<endl;

signed main() {
  int a,b;cin>>a>>b;
  --a;

  int maxDigit=0;
  while(b>(1LL<<maxDigit)) ++maxDigit;

  int ans = 0;
  for(int digit=1;digit<=maxDigit;++digit){
    int aa=0,bb=0;
    if (digit==1){
      aa = (a % 4) <= 2;
      bb = (b % 4) <= 2;
      int tmp = abs(aa-bb)%2;
      ans += tmp;
      continue;
    }
    
    if((b - ((1LL<<(digit-1)) - 1))>=0)
      bb = max(((b - ((1LL<<(digit-1)) - 1)) % (1LL<<digit)), (1LL<<(digit-1))) % 2;

    debug((b - ((1LL<<(digit-1)) - 1)));
    
    if((a - ((1LL<<(digit-1)) - 1))>=0)
      aa = max(((a - ((1LL<<(digit-1)) - 1)) % (1LL<<digit)), (1LL<<(digit-1))) % 2;
    int tmp = abs(aa-bb)%2;
    ans += (1LL<<(digit)) * tmp;
    debug(aa);
    debug(bb);
    debug(tmp);
    debug(ans);
  }
  cout<<ans<<endl;
  return 0;
}
