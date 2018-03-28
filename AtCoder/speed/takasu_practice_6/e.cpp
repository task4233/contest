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

int N, C, K;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C >> K;
  vector< int > T(N);
  REP(i, N)
    cin >> T[i];

  sort(ALL(T));

  int limit = T[0] + K;
  int cnt = 0;
  int ans = 0;
  REP(i, N) {
    cnt++;
    /*
    debug(T[i]);
    debug(i);
    debug(cnt);
    debug(ans);
    debug(limit);
    */
    if (T[i] > limit) {
      cnt = 1;
      if (i < N - 1) {
	limit = T[i] + K;
      }
      ans++;
    }
    if (cnt == C) {
      cnt = 0;
      ans++;
      limit = T[i + 1] + K;
    }
    /*
    debug(i);
    debug(cnt);
    debug(ans);
    debug(limit);
    */
  }

  if (cnt > 0) ans++;
  
  cout << ans << endl;
  
  return 0;
}
