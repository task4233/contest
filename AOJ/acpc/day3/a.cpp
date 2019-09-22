#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,m;cin>>n>>m;
  vector<string> a(n),b(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  for(int i=0;i<n;++i){
    cin>>b[i];
  }

  int ans = 0;
  for(int hi=0;hi<n;++hi){
    for(int wi=0;wi<m;++wi){
      if(a[hi][wi]!=b[hi][wi]) ++ans;
    }
  }
  cout<<ans<<endl;
  return 0;
}
