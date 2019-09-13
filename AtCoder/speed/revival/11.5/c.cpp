#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int check(vector<int> t){
  int res = 24;
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  
  for(int i=0;i<t.size();++i){
    int diff = abs(t[i]-t[(i+1)%t.size()]);
    res = min(min(24-diff, diff), res);
  }
  
  if (res>12) return 0;
  return res;
}

signed main() {
  int n;cin>>n;
  vector<int> c(13,0);
  for(int i=0;i<n;++i){
    int f;cin>>f;
    ++c[f];
  }

  if(c[0]){
    cout<<0<<endl;
    return 0;
  }
  
  vector<int> single, db;
  for(int i=0;i<13;++i){
    if(c[i]>=3) {
      cout<<0<<endl;
      return 0;
    }
    else if(c[i]==2) db.push_back(i);
    else if(c[i]==1) single.push_back(i);
  }
  
  int ans = 0;
  vector<int> table;
  table.push_back(0);
  for(int i=0;i<db.size();++i){
    table.push_back(db[i]);
    if (db[i]!=12) table.push_back(24-db[i]);
  }
  
  if (single.size()==0) {
    ans = check(table);
  }
  
  for(int bit=0;bit<(1<<single.size());++bit){
    vector<int> p(single);
    for(int i=0;i<single.size();++i){
      if((bit>>i) & 1) {
        p[i] = 24 - p[i];
      }
    }

    vector<int> tt(table);
    for(int i=0;i<single.size();++i){
      tt.push_back(p[i]);
    } 
    ans = max(check(tt), ans);
  }

  cout<<ans<<endl;
  
  return 0;
}
