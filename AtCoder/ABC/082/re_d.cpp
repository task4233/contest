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
const int MAX_N = 8080;

#define p(n) (8000 + n)

bool dpX[MAX_N][2 * MAX_N];
bool dpY[MAX_N][2 * MAX_N];

string S;
int X, Y;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> S;
  cin >> X >> Y;

  int cnt = 0;
  // true:X / false:Y
  bool dist = true;
  
  REP(si, S.size()) {
    if (S[si] != 'F') break;
    cnt++;
  }
  // debug(cnt);
  
  dpX[cnt][p(cnt)] = dpY[cnt][p(0)] = true;
  if (cnt == 0)
    dist = !dist;

  int tmp = max(cnt, 1);
  cnt = 0;
  
  FOR(si, tmp, S.size() + 1) {
    if (S[si] == 'T' or si == S.size()) {
      if (dist) {
	// X方向
	REP(i, 2 * MAX_N) {
	  if (dpX[si - cnt - 1][i]) {
	    dpX[si][i + cnt] = true;
	    dpX[si][i - cnt] = true;
	  }
	  if (dpY[si - cnt - 1][i]) dpY[si][i] = true;
	}
      } else {
	// Y方向
	REP(i, 2 * MAX_N) {
	  if (dpY[si - cnt - 1][i]) {
	    dpY[si][i + cnt] = true;
	    dpY[si][i - cnt] = true;
	  }
	  if (dpX[si - cnt - 1][i]) dpX[si][i] = true;
	}
      }
      dist = !dist;
      cnt = 0;
    } else {
      // F
      cnt++;
    }
  }

  bool ok = false;
  if (dpX[S.size()][p(X)] && dpY[S.size()][p(Y)])
    ok = true;

  OK(ok);

  /*
  FOR(i, -5, 6) {
    debug(i);
    OK(dpX[S.size()][p(i)]);
  }

  FOR(i, -5, 6) {
    debug(i);
    OK(dpY[S.size()][p(i)]);
  }
  */
  
  return 0;
}

