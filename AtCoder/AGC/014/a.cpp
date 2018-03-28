// ------------------------------------
// Date:2018/ 3/15
// Problem:AGC 014 CookieExchanges a.cpp
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

int solve(int a, int b, int c)
{
  if (not(a % 2 == 0 and b % 2 == 0 and c % 2 == 0)) return 0;
  if (a == b and b == c) return -1;
  return solve((a + b) / 2, (b + c) / 2, (a + c) / 2) + 1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  int ans = solve(a, b, c);
  cout << ans << endl;
  
  return 0;
}

