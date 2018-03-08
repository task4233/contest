// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 002 RangeProduct a.cpp
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
  int a,b;
  cin >> a >> b;
  if (a>0) {
    cout << "Positive" << endl;
  } else if (b>0) {
    cout << "Zero" << endl;
  } else {
    cout << ((b-a+1)%2==0?"Positive":"Negative") << endl;
  }
  return 0;
}

