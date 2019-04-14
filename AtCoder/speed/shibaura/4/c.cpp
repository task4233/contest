#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

// 1
// 12
// 312
// 3124

vector<int> ans;
signed main() {
  int n;cin>>n;
  deque<int> q;
  for(int i=0;i<n;++i) {
    int a;cin>>a;
    if(i%2) {
      q.push_front(a);
    }else{
      q.push_back(a);
    }
  }

  for_each(q.begin(), q.end(), [](int x){
                                 ans.push_back(x);
                               });
  
  if(n%2==1) reverse(ans.begin(),ans.end());
  bool isFirst = true;
  for(int i=0;i<n;++i){
    if(isFirst) isFirst = false;
    else cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
  
  return 0;
}
