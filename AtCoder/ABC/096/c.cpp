// ------------------------------------
// Date:2018/ 5/ 5
// Problem:// / / c.cpp
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
const int MAX_N = 55;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int H, W;
string S[MAX_N];
bool state[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  REP(i, H) {
    cin >> S[i];
  }

  REP(hi, H) {
    REP(wi, W) {
      if (state[hi][wi]) continue;
      if (S[hi][wi] == '#') {
	bool ok = false;
	REP(i, 4) {
	  int y = hi + dy[i];
	  int x = wi + dx[i];
	  if (!(0 <= y && y < H and
		0 <= x && x < W)) continue;

	  if (S[y][x] == '#') {
	    ok = true;
	    state[hi][wi] = true;
	    state[y][x] = true;
	  }
	}
      }
    }
  }

  bool ok = true;
  REP(hi, H) {
    REP(wi, W) {
      if (S[hi][wi] == '#' && !state[hi][wi]) {
	ok = false;
      }
    }
  }

  OK(ok);

  return 0;
}

