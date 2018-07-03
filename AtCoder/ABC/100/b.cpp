#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;


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

  LCIN(D, N);

  ll ans = 0;
  ll tmp = 100;
  FOR(i, 1, D) {
    tmp *= 100;
  }
  if (D == 0){
    REP(i, N) {
      ans++;
      if ((i + 1) % tmp == 0) {
	ans++;
      }
    }
  } else {
    // 愚直にたす
    REP(i, N) {
      ans += tmp;
      if ((ans / tmp) % 100 == 0) {
	ans += tmp;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}

