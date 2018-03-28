// ------------------------------------
// Date:2018/ 3/19
// Problem:A - 正方形のチップ2 a.cpp
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
#define debug(x) cerr << #x << ":" << x << "\n";
#define OK(ok) cout << (ok ? "Yes" : "No") <<　"\n";
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

int K;

bool check(int radius, int x, int y)
{
  if(sqrt((radius - x) * (radius - x) + (radius - y) * (radius - y)) <= radius and
     sqrt((radius - x) * (radius - x) + (radius - y - K) * (radius - y - K)) <= radius and
     sqrt((radius - x - K) * (radius - x - K) + (radius - y) * (radius - y)) <= radius and
     sqrt((radius - x - K) * (radius - x - K) + (radius - y - K) * (radius - y - K)) <= radius) return true;
  return false;
}

int main()
{
  int ans1, ans2;
  ans1 = ans2 = 0;
  scanf("%d", &K);
  REP(xi, 300) {
    REP(yi, 300) {
      int x = xi * K;
      int y = yi * K;
      if (check(100, x, y)) ans1++;
      if (check(150, x, y)) ans2++;
    }
  }

  printf("%d %d\n", ans1, ans2);

  return 0;
}

