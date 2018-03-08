// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 046 AtCoDeerAndElectionReport c.cpp
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

using ll = long long;

#define MOD 1000000007

int main()
{
  int N;
  ll currentT,currentA,lastT,lastA,tmp;
  lastT = lastA = 1;
  cin >> N;
  REP(i,N) {
    cin >> currentT >> currentA;
    // 保持したlastTとlastAのうち大きい方をかけて上書き
    tmp = max(lastT/currentT + (lastT%currentT==0?0:1),
              lastA/currentA + (lastA%currentA==0?0:1));
    lastT = tmp*currentT;
    lastA = tmp*currentA;
  }
  cout << lastA+lastT << endl;
  return 0;
}

