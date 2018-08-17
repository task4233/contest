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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< double > t(N);
  REP(i, N) {
    cin >> t[i];
  }
  vector< double > v(N);
  REP(i, N) {
    cin >> v[i];
  }

  int T = 0;
  REP(i, N) {
    T += t[i];
  }

  vector< double > maxV(2 * T + 1, (double)INF);
  int current_time = 0;
  REP(i, N) {
    REP(j, t[i]) {
      int t0 = current_time + j * 2;
      int t1 = current_time + j * 2 + 1;
      maxV[t0] = min(maxV[t0], v[i]);
      maxV[t1] = min(maxV[t1], v[i]);
    }
    current_time += 2 * t[i];
    maxV[current_time] = min(maxV[current_time], v[i]);
  }
  /*
  REP(i, 2 * T + 1) {
    printf("%.1f: %f\n", (double)i * 0.5, maxV[i]);
  }
  */
  
  maxV[0] = maxV[2 * T] = 0;

  REP(i, 2 * T) {
    maxV[i + 1] = min(maxV[i + 1], maxV[i] + 0.5);
  }

  RREP(i, 2 * T) {
    maxV[i] = min(maxV[i], maxV[i + 1] + 0.5);
  }

  double ans = 0.0;
  REP(i, 2 * T) {
    ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0;
  }

  // REP(i, 2 * T + 1) {
  //   printf("%.1f: %f\n", (double)i * 0.5, maxV[i]);
  // }
  
  // cout << ans << endl;
  printf("%.4f\n", ans);
  return 0;
}

