// ------------------------------------
// Date:2018/ 3/17
// Problem:ABC 022 BumbleBee b.cpp
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
static const int MAX_N = 101010;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  map< int, int > m;
  REP(i, N) {
    CIN(a);
    m[a - 1]++;
  }
  int ans = 0;
  REP(i, m.size()) {
    if (m[i] > 1) ans += m[i] - 1;
    //debug(m[i]);
  }

  cout << ans << endl;

  return 0;
}

