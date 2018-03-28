// ------------------------------------
// Date:2018/ 2/25
// Problem:SRM407 Div2 Level2 CorporationSalary.cpp
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

class CorporationSalary {
public:
  ll totalSalary(vector<string> relations)
  {
    ll ans = 0ll;
    REP(ri, relations.size()) {
      ans += dfs(ri, relations);
    }
    return ans;
  }
private:
  ll salaries[50] = {0ll};
  ll dfs(int n, vector<string> relations)
  {
    if (salaries[n] != 0ll) return salaries[n];
    ll sum = 0ll;
    string relation = relations[n];
    REP(ri,relation.size()) {
      if (relation[ri] == 'Y') {
        sum += dfs(ri, relations);
      }
    }
    if (sum == 0ll) sum = 1ll;
    salaries[n] = sum;
    return salaries[n];
  }
};

int main()
{
  CorporationSalary c;
  vector<string> input;
  string tmp;
  while (cin >> tmp) {
    if (tmp == "end") break;
    input.emplace_back(tmp);
  }
  cout << c.totalSalary(input) << endl;
  return 0;
}

