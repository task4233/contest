// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 044 TakAndHotels a.cpp
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

int main()
{
  int N,K,X,Y,res = 0;
  cin >> N >> K >> X >> Y;
  REP(i,N) res += i<K?X:Y;
  cout << res << endl;
  return 0;
}

