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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  LCIN(x);
  vector< pair< ll, int > > a(N);
  ll mnNum = LINF;
  int mn = 0;
  REP(i, N) {
    LCIN(t);
    a[i] = make_pair(t, i);
  }

  /*
  vector< int > p(N);
  iota(ALL(p), 0);
  */
  /*
  EACH(pi, p) {
    debug(pi);
  } 
  */
  // debug(a[mn]);

  sort(ALL(a));
  // reverse(ALL(a));
  
  ll ans = LINF;
  REP(h, N){
    ll tmp = 0ll;
    int xNum = 0;
    REP(i, N) {
      int j = a[0].second;
      if (a[h].second == j) {
	tmp += a[h].first;
      } else {
	if (a[h].first < ((a[h].second - j + N) % N) * x) {
	  tmp += min(a[h].first, a[j].first + ((a[h].second - j + N) % N) * x);
	} else {
	  xNum = max(xNum, (a[h].second - j + N) % N);
	  tmp += a[j].first;
	}
	// debug(min(a[p[i]], a[j] + ((p[i] - j + N) % N) * x));
      }
    }
    tmp += xNum * x;
    ans = min(ans, tmp); 
  }
  // while(next_permutation(ALL(p)));

  cout << ans << endl;

  return 0;
}

