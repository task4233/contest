// ------------------------------------
// Date:2018/ 3/20
// Problem:A- Simple Calculator a.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int INF = 2e9 + 1;
static const int MAX_N = 1;

ll solve(ll x, ll y)
{
  if (y - x < 0) return INF;
  return y - x;
}

int main()
{
  LCIN(X, Y);
  ll ans = INF;
  ans = min(ans, solve(X, Y));
  ans = min(ans, solve(X, -Y) + 1);
  ans = min(ans, solve(-X, Y) + 1);
  ans = min(ans, solve(-X, -Y) + 2);
  cout << ans << endl;

  return 0;
}

