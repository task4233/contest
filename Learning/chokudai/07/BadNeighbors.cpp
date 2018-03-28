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
    int ans = 0;
    REP(i,donations.size()) {
      ans = max(dfs(i,donations),ans);
      debug(i);
      debug(dfs(i,donations));
    }
    return ans;
  }
private:
  int donationMemo[1000] = {0};
  int dfs(int i, vector<int> donations) {
    int sum = 0;
    if (donationMemo[i] == 0) {
      for(int j=0; j<donations.size()*2; j+=2) {
        sum += donations[j];
      }
      donationMemo[i] = sum;
    }
    return donationMemo[i];
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

