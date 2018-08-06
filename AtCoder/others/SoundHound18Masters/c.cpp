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

long double n, m, d;

int main()
{

  cin >> n >> m >> d;
    if (d == 0) {
    // OK(false);
    long double t = 1.0;
    //t /= pow((double)n, m - 1);
    t = m / n;
    printf("%.16Lf\n", t);
    return 0;
  }
  if (1.0 + d > n) {
    // OK(true);
    long double f = 0.0;
    printf("%.16Lf\n", f);
    return 0;
  }

  long double tmp = 0.0;
  /*
  FOR(i, 1, n + 1) {
    if ((i + d) <= n) {
      tmp += 2.0;
    }
  }
  */
  tmp += 2.0 * (n - d) * (m - 1.0);
  tmp /= n;
  tmp /= n;

  // debug(tmp);
  // long double ans = tmp * (m - 1.0);
  // debug(ans);
  printf("%.16Lf\n", tmp);

  return 0;
}

