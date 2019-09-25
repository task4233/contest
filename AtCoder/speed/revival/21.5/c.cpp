#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

signed main() {
  int n,m;cin>>n>>m;
  vector<int> p(n);
  for(int i=0;i<n;++i) cin>>p[i];

  vector<int> a(n*n);
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      a[i*n+j] = p[i] + p[j];
    }
    a.emplace_back(p[i]);
  }

  sort(a.begin(),a.end());
  
  auto check = [&](int mid) {
                 bool res = false;
                 //debug(mid);
                 for(int i=0;i<a.size();++i) {
                   int rest = mid-a[i];
                   //debug(rest);
                   if (binary_search(a.begin(), a.end(), rest)) {
                     res = true;
                   }
                 }
                 return res;
               };
  
  for(int i=m;i>=0;--i) {
    if(check(i)) {
      cout<<i<<endl;
      return 0;
    }
  }
  return 0;
}
