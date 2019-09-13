#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<(x)<<endl;

signed main() {
  int n;cin>>n;
  vector<int> d;
  vector<int> c(13,0);
  for(int i=0;i<n;++i) {
    int f;cin>>f;
    ++c[f];
  }

  vector<int> db;
  for(int i=0;i<13;++i){
    if(c[i]==1) d.push_back(i);
    if(c[i]>1) db.push_back(i);
  }

  
  int ans = 0;

  vector<int> pp;
  for(int j=0;j<db.size();++j){
    pp.push_back(db[j]);
    pp.push_back(24-db[j]);
  }
  sort(pp.begin(),pp.end());

  int tmp = 1e9+1;
  for(int j=0;j<pp.size();++j){
    tmp = min(abs(pp[j]-pp[(j+1)%pp.size()]), tmp);
  }
  if (tmp<=12) ans = max(ans, tmp);

  
  n = d.size();
  for(int bit=0;bit<(1<<n);++bit){
    for(int i=0;i<n;++i){
      vector<int> p(d);
      for(int j=0;j<db.size();++j){
        p.push_back(db[j]);
        p.push_back(24-db[j]);
      }
      
      if ((bit>>i) & 1) {
        p[i] = 24 - p[i];
      }

      int tmp = 1e9+1;
      for(int j=0;j<p.size();++j){
        tmp = min(abs(p[j]-p[(j+1)%p.size()]), tmp);
      }

      if (tmp<=12) ans = max(ans, tmp);
    }
  }
  cout<<ans<<endl;
  
  return 0;
}
