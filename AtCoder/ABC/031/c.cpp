
// ------------------------------------
// Date:2018/ 3/30
// Problem:C - 数列ゲーム c.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > a(N);
  REP(i, N)
    cin >> a[i];


  int ans = -INF;
  int TakahashiSum, AokiSum;
  REP(tPoint, N) {
    TakahashiSum = AokiSum = -INF;
    REP(aPoint, N) {
      int lb = min(tPoint, aPoint);
      int ub = max(tPoint, aPoint);
      int evenSum = 0;
      int oddSum = 0;
      if (lb == ub) continue;
      FOR(i, lb, ub + 1) {
	if ((i + lb) & 1) evenSum += a[i];
	else oddSum += a[i]; 
      }
      if (evenSum > AokiSum) {
	AokiSum = evenSum;
	TakahashiSum = oddSum;
      }
      debug(tPoint);
      debug(aPoint);
      debug(AokiSum);
      debug(TakahashiSum);
      debug(evenSum);
      debug(oddSum);
    }
    ans = max(ans, TakahashiSum);
    debug(ans);
  }

  cout << ans << endl;

  
  return 0;
}

