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
const int MAX_N = 3e2 + 1;

int N;
string s[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) {
    cin >> s[i];
  }
  
  int ans = 0;

  // A = 0で固定
  REP(bi, N) {
    bool ok = true;
    REP(hi, N) {
      REP(wi, N) {
	int width = wi;
	if (hi == 0) {
	  width = wi + bi;
	  if (width >= N) width -= N;
	}
	debug(s[hi][width]);
	debug(s[wi][hi]);
	if (s[hi][width] != s[width][hi]) ok = false;
      }
    }
    if (ok) ans++;
  }

  cout << ans << endl;

  return 0;
}

