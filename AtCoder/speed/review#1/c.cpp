// ------------------------------------
// Date:2018/ 3/24
// Problem:Digits in Multiplication c.cpp
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
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int check(ll a)
{
  string tmp = to_string(a);
  return tmp.size();
}

int main()
{
  LCIN(N);
  // 高々√N
  int ans = INF;
  FOR(i, 1, sqrt(N) + 1) {
    if (N % i == 0) {
      ans = min(ans, max(check(N / i), check(i)));
      // debug(N);
      // debug(N / i);
      // debug(ans);
    }
  }

  cout << ans << endl;
  return 0;
}

