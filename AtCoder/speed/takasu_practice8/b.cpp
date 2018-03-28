// ------------------------------------
// Date:2018/ 3/17
// Problem:C- Big Array b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
static const int MOD = 1000000007;
static const int MAX_N = 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, K);
  vector< pair< ll, ll > > a(N);
  REP(i, N) {
    CIN(p, q);
    a[i] = make_pair(p, q);
  }

  sort(ALL(a), [](pair< ll, ll > x, pair< ll, ll > y) { return x.first < y.first; } );

  ll cnt = 0;
  ll ans = a[cnt].first;
  REP(i, N) {
    ans = a[i].first;
    cnt += a[i].second;
    if (cnt > K -1) break;
  }

  cout << ans << endl;
  
  return 0;
}

