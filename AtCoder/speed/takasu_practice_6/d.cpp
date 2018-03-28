// ------------------------------------
// Date:2018/ 3/26
// Problem:A - 動く歩道 d.cpp
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

const double INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

double l, x, y, s, d;

double res(double n)
{
  if (n < 0) return n + l;
  return n;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> l >> x >> y >> s >> d;

  double ans;
  if (y > x) {
    if (d > s) {
      cout << 1 << endl;
      ans = min(res((d - s) / (x + y)), res((s + l - d) / (y - x)));
    } else {
      cout << 2 << endl;
      ans = min(res((l + d - s) / (x + y)), res((s - d) / (y - x)));
    }
  } else {
    if (d > s) {
      cout << 3 << endl;
      ans = (d - s) / (x + y);
    } else {
      cout << 4 << endl;
      ans = (l + d - s) / (x + y);
    }
  }

  printf("%.7lf\n", ans);

  return 0;
}

