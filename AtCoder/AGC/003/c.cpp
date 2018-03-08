// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 003 BBuBBBlesort! c.cpp
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

// -----------------------------------------------
// 奇数番号のものは奇数番号のものと、
// 偶数番号のものは偶数番号のものとノーコストで交換できる。
// できない時に++cntすればおk
// -----------------------------------------------

int main()
{
  int N,tmp,cnt = 0;
  cin >> N;
  vector<int> Gift(N);
  REP(i,N) {
    cin >> Gift[i];
  }
  vector<int> Tmp(Gift);
  sort(ALL(Tmp));
  REP(i,N) {
    // 偶数番号のものに偶数番号のものが入っていない、もしくはその逆ならば++cnt
    tmp = int(lower_bound(ALL(Tmp),Gift[i])-Tmp);
    if (tmp%2==1) ++cnt;
  }
  cout << cnt/2 << endl;
  
  return 0;
}
