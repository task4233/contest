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

  CIN(N);
  pair< string, string > S;
  cin >> S.first >> S.second;
  // debug(S.first);
  // debug(S.second);
  
  ll ans = 1ll;
  
  int last = -1;
  // 0: 縦/ 1: 横
  int state;
  REP(i, N) {
    // debug(S.first[i]);
    // debug(S.second[i]);
    if (S.first[i] == S.second[i]) {
      // 縦
      state = 0;
    } else {
      // 横
      state = 1;
      // 横の時は2マス占領するためi++する必要がある。
      i++;
    }
    // debug(state);

    if (last == -1) {
      // 初回
      if (state == 0) {
	// 縦
	ans *= 3ll;
      } else {
	ans *= 3ll * 2ll;
      }
    } else if (last == 0) {
      // 縦
      (ans *= 2ll) %= MOD;
    } else {
      // 横
      if (state == 1) {
	// 縦
	(ans *= 3ll) %= MOD;
      }
    }
    last = state;
    // debug(last);
    // debug(ans);
  }
  cout << ans << endl;

  return 0;
}

