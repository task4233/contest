// ------------------------------------
// Date:2018/ 3/19
// Problem:Make a Rectangle c.cpp
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
static const int MAX_N = 1e9 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int _min = -1;
  CIN(N);
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  sort(ALL(a), greater< int >());

  REP(i, N) {
  }
  vector< ll > t;
  REP(i, MAX_N) {
    if (p[i] > 1) {
      REP(j, p[i] / 2) {
	t.emplace_back(i + 1);
      }
    }
  }
  ll ans;
  if (t.size() < 2) ans = 0;
  else {
    sort(ALL(t));
    reverse(ALL(t));
    ans = t[0] * t[1];
  }
  cout << ans << endl;
  return 0;
}

