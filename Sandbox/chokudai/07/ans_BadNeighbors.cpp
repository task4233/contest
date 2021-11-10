// ------------------------------------
// Date:2018/ 2/25
// Problem:2004TCCCOnlineRound4 Div1 Level1 Badneighbors.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

class Badneighbors {
public:
  int maxDonations(vector<int> donations)
  {
    int i;
    int ans = 0;
    int N = donations.size();
    int *dp = new int[N];
    
    // 偶数番目
    REP(i,N-1) {
      dp[i] = donations[i];
      if (i > 0) dp[i] = max(dp[i],dp[i-1]);
      if (i > 1) dp[i] = max(dp[i], dp[i-2] + donations[i]);
      ans = max(dp[i], ans);
    }
    
    // 奇数番目
    REP(i,N-1) {
      dp[i] = donations[i+1];
      if (i > 0) dp[i] = max(dp[i], dp[i-1]);
      if (i > 1) dp[i] = max(dp[i], dp[i-2] + donations[i+1]);
      ans = max(dp[i], ans);
    }
    delete[] dp;
    return ans;
  }
};

int main()
{
  Badneighbors b;
  vector<int> donations;
  int n;
  while(cin >> n) {
    if (n == 0) break;
    donations.emplace_back(n);
  }
  cout << b.maxDonations(donations) << endl;
  return 0;
}

