// ------------------------------------
// Date:2018/ 3/21
// Problem:Shik and Stone a.cpp
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
#define OK(ok) cout << (ok ? "Possible" : "Impossible") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int H, W;
string a[8];

bool check()
{
  REP(hi, H) {
    REP(wi, W) {
      // 左下
      if (0 < hi and wi < W - 1) {
	if (a[hi][wi] == '#') {
	  if (a[hi - 1][wi + 1] == '#') return false;
	}
      }
      // 右下
      if (0 < wi and hi < H - 1) {
	if (a[hi][wi] == '#') {
	  if (a[hi + 1][wi - 1] == '#') return false;
	}
      }
    }
  }
  return true;
}

int main()
{
  scanf("%d %d", &H, &W);
  REP(hi, H) {
    cin >> a[hi];
  }

  bool ok = check();
  OK(ok);
  
  return 0;
}

