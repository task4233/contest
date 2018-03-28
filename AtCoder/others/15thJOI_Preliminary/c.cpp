// ------------------------------------
// Date:2018/ 3/20
// Problem:Russian Flag _ c.cpp
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
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int N, M;
string data[55];

int check(int b, int d, char delim)
{
  int res = 0;
  FOR(hi, b, b + d) {
    REP(wi, M) {
      if (data[hi][wi] != delim) res++;
    }
  }
  return res;
}

int main()
{
  scanf("%d %d", &N, &M);
  REP(i, N) {
    cin >> data[i];
  }
  
  int ans = INF;

  int cnt;
  FOR(wi, 1, N - 1) {
    FOR(bi, 1, N - wi) {
      cnt = 0;
      // 白
      cnt += check(0, wi, 'W');
      // 青
      cnt += check(wi, bi, 'B');
      // 赤
      cnt += check(wi + bi, N - wi - bi, 'R');

      debug(cnt);
      ans = min(ans, cnt);
    }
  }

  cout << ans << endl;

  return 0;
}

