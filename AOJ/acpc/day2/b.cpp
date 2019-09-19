#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

signed main() {
  int mul=1, num=0;
  int n;cin>>n;
  for(int i=0;i<n;++i){
    int q,x; cin>>q>>x;
    switch(q){
    case 1:
      mul *= x;
      num *= x;
      break;
    case 2:
      num += x;
      break;
    case 3:
      num -= x;
      break;
    }
    // debug(num);
    // debug(mul);
  }
  cout << -num << " " << mul << endl;
  return 0;
}
