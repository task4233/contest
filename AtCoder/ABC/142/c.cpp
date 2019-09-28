#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

signed main() {
  INIT;
  int n;cin>>n;
  vector< pair<int,int> > a(n);
  for(int i=0;i<n;++i) {
    int p;cin>>p;
    a[i] = make_pair(p,i);
  }

  sort(a.begin(), a.end());
  for(int i=0;i<n;++i){
    if(i>0) cout<<" ";
    cout<<a[i].second+1;
  }
  cout<<endl;
  return 0;
}
