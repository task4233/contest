#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

// dpっぽい
// 20 4
// 3 7 8 4

// 20本のマッチを作るために
// 20-a[i]本のマッチで作れればおk
// 

// dp[i] := i本マッチの使った時の最大値
// 大きいほうから使ったほうが良い

string dp[10101];
int cost[10] = {10101010101,2,5,5,4,5,6,3,7,6};

signed main() {
  int n,m;cin>>n>>m;
  vector<int> a(m);
  for(int i=0;i<m;++i) {
    cin>>a[i];
  }

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  auto check = [&](string p, string q){
                 if(p.size()==q.size()){
                   return p>q;
                 }
                 return p.size() > q.size();
               };
  
  fill_n(dp,10101,"0");
  dp[0] = "";
  for(int i=0;i<=n;++i){
    for(int j=0;j<m;++j){
      if(i-cost[a[j]]>=0){
        if(dp[i-cost[a[j]]]=="0") continue;
        string tmp = to_string(a[j]) + dp[i-cost[a[j]]];
        if(check(tmp, dp[i])) {
          dp[i] = tmp;
        }
      }
    }
  }

  string ans = dp[n];
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  
  return 0;
}
