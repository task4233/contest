#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "YES" : "NO") << endl;
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
const int MAX_N = 1e3 + 1;
const int MAX_M = 1e3 + 1;

int N, M;
ll sum[MAX_N];
ll d[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  bool ok = false;
  REP(i, M) {
    memset(sum, 0, sizeof(sum));
    REP(j, N) {
      ll a; cin >> a;
      sum[j + 1] = sum[j] + a;
      d[j + 1] += sum[j + 1];
      // debug(d[j + 1]);
    }
    int ub = 0;
    REP(j, N + 1) {
      if (d[j] == 777) ok = true;
      REP(k, j) {
	if (d[j] - d[k] == 777) ok = true;
      }
    }
  }

  OK(ok);
  
  return 0;
}

