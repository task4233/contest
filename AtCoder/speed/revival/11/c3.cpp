#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int check(vector<int> t){
  int res = 1e9+1;
  for(int i=0;i<t.size();++i){
    res = min(abs(t[i]-t[(i+1)%t.size()]), res);
  }
  return res;
}

signed main() {
  int n;cin>>n;
  vector<int> c(13,0);
  for(int i=0;i<n;++i){
    int f;cin>>f;
    ++c[f];
  }

  vector<int> single, db;
  for(int i=0;i<13;++i){
    if(c[i]>1) db.push_back(i);
    else if(c[i]==1) single.push_back(i);
  }

  int ans = 0;
  vector<int> table(24,0);
  for(int i=0;i<db.size()){
    ++table[db[i]];
    ++table[24-db[i]];
  }
  ans = check(table);

  for(int bit=0;bit<(1<<single.size());++bit){
    vector<int> p(single);
    for(int i=0;i<single.size();++i){
      if((bit>>i) & 1) {
        p[i] = 24 - p[i];
      }
    }

    ans = max(check(p), ans);
  }

  cout<<ans<<endl;
  
  return 0;
}
