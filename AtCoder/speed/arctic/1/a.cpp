#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;
constexpr int INF = 1LL<<60;

int dp[44][4040][4040];

signed main() {
  int n,ma,mb; cin>>n>>ma>>mb;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;++i) cin>>a[i]>>b[i]>>c[i];

  for(int i=0;i<44;++i)
    for(int j=0;j<4040;++j)
      fill_n(dp[i][j], 4040, INF);

  dp[0][0][0] = 0;

  for(int i=0;i<n;++i){
    for(int j=0;j<4040;++j){
      for(int k=0;k<4040;++k){
        if(j-a[i]>=0 && k-b[i]>=0) {
          dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a[i]][k-b[i]] + c[i]);
        } else {
          dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        }
      }
    }
  }

  int ans = INF;
  for(int i=1;i<=4004/min(ma,mb);++i){
    ans = min(ans, dp[n][ma*i][mb*i]);
    if(dp[n][ma*i][mb*i]==0) {
      debug(ma*i);
      debug(mb*i);
    }
  }
  if(ans==INF) ans = -1;
  cout<<ans<<endl;
  debug(dp[1][1][2]);
  
  return 0;
}
