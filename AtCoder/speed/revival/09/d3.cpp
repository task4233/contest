#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int f(int n){
  if (n<=0) return 0;
  return (((n+1)/2)%2) ^ (n%2==0?n:0);
}

signed main() {
  int a,b;cin>>a>>b;
  int ans = f(b)^f(a-1);
  cerr<<f(b)<<endl;
  cerr<<f(a-1)<<endl;
  cout<<ans<<endl;
  return 0;
}

