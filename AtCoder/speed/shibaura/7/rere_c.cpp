#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<" "<<x<<endl;

signed main() {
  int n;cin>>n;
  int s,t;
  bool isFirst=true;
  for(int i=0;i<n;++i){
    int p,q;cin>>p>>q;
    if(isFirst){
      s=p;t=q;
      isFirst=false;
      continue;
    }
    
    int tmp = max((s+p-1)/p, (t+q-1)/q);
    s=tmp*p;
    t=tmp*q;
    debug(s);
    debug(t);
  }
  cout<<s+t<<endl;
  return 0;
}
