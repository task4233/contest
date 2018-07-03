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

ll N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  ll ans = 0ll;
  REP(i, N) {
   
  }

  cout << ans << endl;
  
  return 0;
}


それぞれの区間で、10進表記した際に含まれる1の数

(0, 9]		=        0 * 10 + 1           = 1[個]
(0, 99]		=        1 * 10 + 10          = 20[個]
(0, 999]	=       20 * 10 + 100         = 300[個]
(0, 9999]	=      300 * 10 + 1000        = 4000[個]
(0, 99999]	=     4000 * 10 + 10000       = 50000[個]
(0, 999999]	=    50000 * 10 + 100000      = 600000[個]
(0, 9999999]	=   600000 * 10 + 1000000     = 7000000[個]
(0, 99999999]	=  7000000 * 10 + 10000000    = 80000000[個]
(0, 999999999]	= 80000000 * 10 + 100000000   = 900000000[個]

		 
