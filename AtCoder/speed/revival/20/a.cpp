#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin>>a[i];
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()), a.end());
  a.pop_back();
  cout<<a.back()<<endl;
  return 0;
}
