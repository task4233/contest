#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> ans(n,k-q);
  for(int i=0;i<q;++i){
    int a;cin>>a;--a;
    ans[a]++;
  }

  for(int i=0;i<n;++i){
    if (ans[i] <= 0LL) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}
