#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,k;cin>>n>>k;
  vector<int> a(n,0);
  int p;
  for(int i=0;i<k;++i) {
    cin>>p;
    a[--p] = 1;
  }
  vector<string> s(n);
  for(int i=0;i<n;++i) cin>>s[i];

  string ans=s[p];
  for(int i=0;i<n;++i) {
    if(!a[i]) continue;
    int cnt = 0;
    for(int j=0;j<min(ans.size(), s[i].size());++j) {
      if(ans[j]==s[i][j]) ++cnt;
      else break;
    }
    // substrで再代入せずともresizeでおk
    ans.resize(cnt);
  }

  int mx = -1;
  for(int i=0;i<n;++i) {
    if(a[i]) continue;
    int cnt = 0;
    for(int j=0;j<min(ans.size(), s[i].size());++j) {
      if(ans[j]==s[i][j]) ++cnt;
      else break;
    }
    mx = max(mx, cnt);
  }

  if(mx==ans.size()){
    cout<<-1<<endl;
  }else{
    cout<<ans.substr(0,mx+1)<<endl;
  }

  return 0;
}
