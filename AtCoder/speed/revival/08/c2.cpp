#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,p;cin>>n>>p;
  for(int i=p;i>=i;--i){
    int j=1;
    for(int k=0;k<n;++k){
      j *= i;
    }
    if (p%j==0) {
      cout << i << endl;
      break;
    }
  }
  cout<<1<<endl;
  
  return 0;
}
