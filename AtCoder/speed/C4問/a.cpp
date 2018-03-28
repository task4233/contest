// ------------------------------------
// Date:2018/ 3/25
// Problem:C - 4-adjacent a.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

bool check(int fCnt, int tCnt, int oCnt)
{
  if (tCnt == 0) {
    if (oCnt > fCnt + 1) {
      return false;
    } else {
      return true;
    }
  } else {
    if (oCnt > fCnt) {
      return false;
    } else {
      if (oCnt > fCnt) {
	return false;
      } else {
	return true;
      }
    }
  }
}

int main()
{
  int N;
  scanf("%d", &N);
  vector< int > a(N);
  int fCnt, tCnt, oCnt;
  fCnt = tCnt = oCnt = 0;
  REP(i, N) {
    scanf("%d", &a[i]);
    if (a[i] % 4 == 0) fCnt++;
    else if (a[i] % 2 == 0) tCnt++;
    else oCnt++;
  }

  bool ok = check(fCnt, tCnt, oCnt);

  OK(ok);
  return 0;
}

