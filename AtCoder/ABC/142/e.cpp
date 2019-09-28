#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

int n,m;
int dp[1<<15][1010];
vector<int> a;
vector<int> c[1010];
vector<int> states;

signed main() {
  INIT;
  cin>>n>>m;
  a.resize(m);states.resize(m);
  for(int i=0;i<m;++i){
    cin>>a[i];
    int b;cin>>b;
    c[i].resize(b);
    int state = 0;
    for(int j=0;j<b;++j) {
      cin>>c[i][j];
      c[i][j]--;
      state |= (1<<c[i][j]);
    }
    states[i] = state;
  }

  for(int i=0;i<(1<<n);++i) fill_n(dp[i], 1010, 1e9+1);
  dp[0][0] = 0;
  
  for(int bit=0;bit<(1<<n);++bit){
    for(int j=0;j<m;++j){
      //debug(j);
      //debug(states[j]);
      if (j>0) dp[bit][j] = min(dp[bit][j], dp[bit][j-1]);
      if(dp[bit | states[j]][j] > dp[bit][j] + a[j]) {
        dp[bit | states[j]][j] = dp[bit][j] + a[j];
        /*
        debug(bit | states[j]);
        debug( dp[bit | states[j]][j]);
        */
      }
    }
  }

  int ans = 1e9+1;
  for(int i=0;i<m;++i){
    ans = min(ans, dp[(1<<n)-1][i]);
  }
  if(ans==1e9+1) ans = -1;
  cout<<ans<<endl;

  /*
  for(int i=0;i<(1<<n);++i){
    for(int j=0;j<m;++j){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  
  return 0;
}
