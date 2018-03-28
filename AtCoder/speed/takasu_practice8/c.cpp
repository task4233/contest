// ------------------------------------
// Date:2018/ 3/17
// Problem:AtCoder プログラミング講座 . c.cpp
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
  CIN(N, K);
  vector< double > R(N);
  REP(i, N) cin >> R[i];
  sort(ALL(R));

  double ans = 0.0;
  FOR(i, N - K, N) {
    ans = (ans + R[i]) / 2.0;
  }

  printf("%.7lf\n", ans);
  
  return 0;
}

