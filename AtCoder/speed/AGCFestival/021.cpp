\// ------------------------------------
// Date:2018/ 3/31
// Problem:Digit Sum 2 021.cpp
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  SCIN(N);
  ll ans = 0ll;
  ll sub = 0ll;
  bool flag = false;
  REP(i, N.size()) {
    sub += N[i] - '0';
  }
  REP(i, N.size()) {
    if (i == 0) {
      // 最初
      if (N[i] == '9') {
	flag = true;
	ans += 9;
      } else {
	ans += (N[i] - '0');
	ans--;
	// OK(true);
      }
    } else {
      if (flag) {
	if (N[i] != '9') {
	  ans -= 1;
	  flag = false;
	}
      }
      ans += 9;
      // debug(ans);
    }
  }

  cout << max(ans, sub) << endl;
  
  return 0;
}

