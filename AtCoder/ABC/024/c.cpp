// ------------------------------------
// Date:2018/ 3/27
// Problem:C - 民族大移動 c.cpp
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

ll N, D, K;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> D >> K;
  vector< ll > L(D);
  vector< ll > R(D);
  REP(i, D) {
    cin >> L[i] >> R[i];
    L[i]--; R[i]--;
  }
  vector< ll > S(K);
  vector< ll > T(K);
  REP(i, K) {
    cin >> S[i] >> T[i];
    S[i]--; T[i]--;
  }

  ll l, r;
  REP(ki, K) {
    l = r = S[ki];
    REP(di, D) {
      if (S[ki] < T[ki]) {
	if (L[di] <= r) {
	  if (R[di] >= r) {
	    r = R[di];
	  }
	  l = L[di];
	  // debug(r);
	  // debug(l);
      }
	if (r >= T[ki]) {
	  // debug(r);
	  cout << di + 1 << endl;
	  break;
	}
      } else {
	if (R[di] >= l) {
	  if (L[di] <= l) {
	    l = L[di];
	  }
	  r = R[di];
	  // debug(r);
	  // debug(l);
	}
	if (l <= T[ki]) {
	  // debug(l);
	  cout << di + 1 << endl;
	  break;
	}
      }
    }
  }

  return 0;
}

