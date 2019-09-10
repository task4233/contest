#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
#define debug(x) cerr << #x << ":" << x << endl;

int main()
{
  int n;cin>>n;
  vector<int> a(n+1);
  for(int i=0;i<n;++i) cin>>a[i+1];

  // 1-indexedにする
  vector<int> memo(n+1,0);
  for(int i=n;i>=1;--i){

    int sm = 0;
    for(int j=i;j<=n;j+=i){
      sm ^= memo[j];
    }
    if (a[i] != sm) memo[i] ^= 1;
  }

  /* 出力*/
  vector<int> ans;
  for(int i=1;i<=n;++i){
    if (memo[i]) ans.push_back(i);
  }

  cout<<ans.size()<<endl;
  for(auto ai: ans){
    cout<<ai<<endl;
  }
  
  return 0;
}
