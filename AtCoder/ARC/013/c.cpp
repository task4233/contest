// ------------------------------------
// Date:2018/ 2/18
// Problem:ARC 013 笑いをとれるかな？ c.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(), (a).end()

vector<int> solve()
{
  int x,y,z,m;
  cin >> x >> y >> z >> m;
  vector<int> mx(m),my(m),mz(m);
  REP(i,m) {
    cin >> mx.at(i) >> my.at(i) >> mz.at(i);
  }
  
  vector<int> res;
  res.emplace_back(*min_element(ALL(mx)));
  res.emplace_back(*min_element(ALL(my)));
  res.emplace_back(*min_element(ALL(mz)));
  res.emplace_back(x - *max_element(ALL(mx)) - 1);
  res.emplace_back(y - *max_element(ALL(my)) - 1);
  res.emplace_back(z - *max_element(ALL(mz)) - 1);
  return res;
}

int main()
{
  int N;
  cin >> N;
  vector<int> nums;
  REP(i,N) {
    vector<int> tmp(solve());
    nums.insert(nums.end(),ALL(tmp));
  }
  
  int res = 0;
  REP(i,nums.size())
  {
    res ^= nums[i];
  }
  
  cout << (res!=0?"WIN":"LOSE") << endl;
  
  return 0;
}

