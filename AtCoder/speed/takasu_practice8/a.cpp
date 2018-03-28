// ------------------------------------
// Date:2018/ 3/17
// Problem:Be together . a.cpp
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
static const int INF = 1000000001;
static const int MAX_N = 100;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }
  sort(ALL(a));

  ll ans = INF;
  (i, a[N - 1]) {
    ll cnt = 0ll;
    REP(j, N) {
      cnt += (a[j] - i) * (a[j] - i);
    }
    ans = min(cnt, ans);
  }

  cout << ans << endl;
  
  return 0;
}

