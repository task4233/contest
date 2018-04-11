#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "possible" : "impossible") << endl;
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

const double PI = atan(1.0);

int H, W;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;
  vector< string > S(H);
  REP(i, H)
    cin >> S[i];

  vector< string > temp(S);
  
  REP(hi, H)
    REP(wi, W) {
      if (S[hi][wi] != '.') continue;
      FOR(yi, -1, 2)
	FOR(xi, -1, 2) {
	int x = wi + xi;
	int y = hi + yi;
	if (!(0 <= x && x < W and
	      0 <= y && y < H)) continue;
	temp[y][x] = '.';
      }
    }

  bool ans = true;
  REP(hi, H)
    REP(wi, W) {
      if (S[hi][wi] !='#') continue;
      if (temp[hi][wi] == '#') continue;

      bool ok = false;
      FOR(yi, -1, 2) {
	FOR(xi, -1, 2) {
	  int x = wi + xi;
	  int y = hi + yi;
	  if (!(0 <= x && x < W and
		0 <= y && y < H)) continue;
	  if (temp[y][x] == '#') ok = true;
	}
      }
      if (!ok) ans = false;
    }

  OK(ans);

  if (ans)
    REP(hi, H)
      cout << temp[hi] << endl;
  
  
  return 0;
}

