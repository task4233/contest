// ------------------------------------
// Date:2018/ 3/20
// Problem:Ice Tea Store a.cpp
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
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const ll LINF = 1e18 + 7;
static const int INF = 1e9 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  LCIN(Q, H, S, D, N);
  ll pQ, pH;
  pQ = Q * 4;
  pH = H * 2;
  ll ans = LINF;
  if (!(N & 1)) {
    // Nが2で割り切れるとき
    ans = min(ans, min(min(min(pQ, pH), S) * N, D * N / 2));
  } else {
    ll tmp = (N / 2) * D; 
    ans = min(min(ans, min(min(pQ, pH), S) * N) , tmp + min(ans, min(min(pQ, pH), S)));
  }
  cout << ans << endl;

  return 0;
}

