#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

signed main() {
  int n;cin>>n;
  priority_queue< int, vector<int>, greater<int> > q;
  for(int i=0;i<n;++i) {
    int p;cin>>p;

    if (q.empty()) {
      q.push(p);
      continue;
    }
    
    vector<int> tmp;
    while(!q.empty()) {
      int r = q.top(); q.pop();
      if (p <= r) break;
      else tmp.emplace_back(r);
    }

    q.push(p);

    for(int j=0;j<tmp.size();++j){
      q.push(tmp[j]);
    }
  }

  cout << q.size() << endl;
  return 0;
}
