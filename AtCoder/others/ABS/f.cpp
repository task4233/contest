// ------------------------------------
// Date:2018/ 3/28
// Problem:Some Sums _ f.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int cnt(string s)
{
  int res = 0;
  EACH(si, s) {
    res += si - '0';
  }
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, A, B);

  ll ans = 0ll;
  FOR(i, 1, N + 1) {
    int tmp = cnt(to_string(i));
    if (A <= tmp && tmp <= B) ans += i;
  }

  cout << ans << endl;

  return 0;
}

