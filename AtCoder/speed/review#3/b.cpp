// ------------------------------------
// Date:2018/ 4/29
// Problem:/ / / b.cpp
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

const ll INF = 1e16 + 5;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

ll N, K;
ll s[MAX_N];
bool state[MAX_N];

ll check(ll n, ll current)
{
  if (!(0 <= n && n < N)) return 0;
  ll lb, ub;
  lb = ub = n;
  if (state[lb]) return 0; 
  
  ll lnum, rnum;
  while(true) {
    state[lb] = state[ub] = true;
    if (lb == 0) lnum = INF;
    else lnum = s[lb - 1];
    if (ub == N - 1) rnum = INF;
    else rnum = s[ub + 1];

    if (lnum == rnum) {
      if (check(lb - 1, current) > check(ub + 1, current)) {
	if (K / current >= lnum) {
	  lb--;
	  current *= lnum;
	} else break;
      } else {
	if (K / current >= rnum) {
	  ub++;
	  current *= rnum;
	} else break;
      }
    } else if (lnum < rnum) {
      if (K / current >= lnum) {
	lb--;
	current *= lnum;
      } else break;
    } else {
      if (K / current >= rnum) {
	ub++;
	current *= rnum;
      } else break;
    }
  }

  return min(ub - lb, N);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(state, false, sizeof(state));
  cin >> N >> K;
  ll mn = INF;
  REP(i, N) {
    cin >> s[i];
    mn = min(mn, s[i]);
  }
  
  if (mn == 0) {
    cout << N << endl;
    return 0;
  }

  if (mn > K) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0ll;
  REP(i, N) {
    ans = max(ans, check(i, mn));
  }

  cout << ans << endl;

  return 0;
}

