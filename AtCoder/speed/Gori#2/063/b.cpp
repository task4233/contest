#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,m;cin>>n>>m;

  vector<int> sto(n);
  iota(sto.begin(), sto.end(), 1);
  int disk=0;
  for(int i=0;i<m;++i) {
    int a;cin>>a;
    for(int j=0;j<n;++j){
      if(a==sto[j]) {
        sto[j] = disk;
        disk = a;
      }
    }

  }

  for(auto &&si: sto){
    cout<<si<<endl;
  }
  
  
  return 0;
}
