// ------------------------------------
// Date:2018/ 3/28
// Problem:Traveling _ _ k.cpp
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
  vector< int > x(N + 1, 0);
  vector< int > y(N + 1, 0);
  vector< int > t(N + 1, 0);
  FOR(i, 1, N + 1)
    cin >> t[i] >> x[i] >> y[i];

  bool ok = true;
  FOR(i, 1, N + 1) {
    int tmp = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    if ((tmp % 2 != (t[i] - t[i - 1]) % 2) or tmp > t[i] - t[i - 1]) {
      // debug(i);
      ok = false;
      break;
    } 
  }
  OK(ok);
  
  return 0;
}

