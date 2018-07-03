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

  CIN(N, T);
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }
  int mn = a[0];
  int mx = a[1];
  int dist = 0;
  int ans = 0;
  REP(i, N - 1) {
    if (a[i] < mn) {
      if (dist < mx - mn) {
	ans = 1;
	dist = mx - mn;
      } else if (dist == mx - mn) {
	ans++;
      }
      mn = a[i];
      mx = a[i];
    }
    // mn = min(mn, a[i]);
    if (a[i + 1] > mx) {
      mx = a[i + 1];
    }
    // mx = max(mx, a[i + 1]);
    //  debug(mn);
    // debug(mx);
  }

  if (dist < mx - mn) {
    ans = 1;
    dist = mx - mn;
  } else if (dist == mx - mn) {
    ans++;
  }

  cout << ans << endl;
  

  return 0;
}

