// ------------------------------------
// Date:2018/ 3/25
// Problem:C - Snuke c.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int N;

int main()
{
  scanf("%d", &N);
  vector< int > A(N);
  REP(i, N) scanf("%d", &A[i]);
  vector< int > B(N);
  REP(i, N) scanf("%d", &B[i]);
  vector< int > C(N);
  REP(i, N) scanf("%d", &C[i]);

  sort(ALL(A));
  sort(ALL(B));
  sort(ALL(C));

  ll ans = 0ll;
  REP(i, N) {
    ll sum = 0ll;
    debug(B[i]);
    sum = lower_bound(ALL(A), B[i]) - A.begin();
    debug(ans);
    sum *= N - (upper_bound(ALL(C), B[i]) - C.begin());
    debug(ans);
    ans += sum;
  }

  cout << ans << endl;
  
  return 0;
}

