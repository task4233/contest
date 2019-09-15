#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,m;cin>>n>>m;
  vector<int> a(n);
  priority_queue<int> q;
  for(int i=0;i<n;++i) {
    cin>>a[i];
    q.push(a[i]);
  }

  for(int i=0;i<m;++i){
    int p = q.top(); q.pop();
    p >>= 1;
    q.push(p);
  }

  int ans = 0;
  for(int i=0;i<n;++i){
    int p = q.top(); q.pop();
    ans += p;
  }

  cout<<ans<<endl;
  
  return 0;
}
