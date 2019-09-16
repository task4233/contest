#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int n,k,q;cin>>n>>k>>q;
  vector<int> score(n,k-q);
  for(int i=0;i<q;++i){
    int a;cin>>a;
    --a;
    score[a] += 1;
  }

  for(int i=0;i<n;++i){
    cout<< ((score[i] > 0) ? "Yes" : "No") <<endl;
    //cerr<<score[i]<<endl;
  }

  
  
  return 0;
}
