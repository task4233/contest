// ------------------------------------
// Date:2018/ 3/10
// Problem:ABC 070 TwoSwitches b.cpp
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

typedef long long ll;

static const int MOD = 1000000007;

int timetable[101];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  fill_n(timetable, 101, 0);
  
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int left = max(a, c);
  int right = min(b, d);
  int ans = right - left;

  if (ans < 0) ans = 0;

  cout << ans << endl;
  
  return 0;
}

