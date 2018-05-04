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
const int MAX_N = 11;

int N, M;

bool e[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    e[a[i]][b[i]] = e[b[i]][a[i]] = true;
  }

  vector< int > ans(N, 0);
  REP(f, N) {
    REP(t, N) {
      vector< int > from;
      vector< int > to;
      REP(k, M) {
	if (a[k] == f) {
	  from.emplace_back(b[k]);
	}
	if (b[k] == t) {
	  to.emplace_back(a[k]);
	}
      }
      // bool ok = false;
      EACH(fi, from) {
	EACH(ti, to) {
	  debug(fi);
	  debug(ti);
	  if (e[fi][ti]) {
	    ans[fi]++;
	    ans[ti]++;
	  }
	}
      }
      //if (ok) ans[f]++;
    }
  }


  REP(i, N) {
    cout << ans[i] << endl;
  }

  return 0;
}

