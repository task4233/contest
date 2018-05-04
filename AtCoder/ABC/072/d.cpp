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

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > p(N);
  REP(i, N) {
    CIN(tmp); tmp--;
    p[i] = i - tmp;
  }

  int last = -1;
  int ans = INF;
  int tmp = 0;
  REP(i, N - 1) {
    if (p[i] == 0 && p[i + 1] == 0) {
      tmp++;
      p[i]++;
      p[i + 1]--;
    }
    // debug(i);
    // debug(tmp);
  }

  REP(i, N) {
    if (p[i] == 0) {
      if (last == -1) last = i;
      else {
	tmp += min(i - last, 2);
	last = -1;
      }
    }
    // debug(i);
    // debug(tmp);
  }
  

  if (last != -1) {
    tmp++;
  }

  ans = min(ans, tmp);
  cout << ans << endl;

  /*
  EACH(pi, p)
    debug(pi);
  */
  
  return 0;
}

