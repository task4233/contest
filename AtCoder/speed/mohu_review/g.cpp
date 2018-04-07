// ------------------------------------
// Date:2018/ 4/ 3
// Problem:shot master _ g.cpp
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

ll H[MAX_N], S[MAX_N];

bool check(ll score)
{
  vector< ll > limits(N);
  REP(i, N) {
    limits[i] = (score - H[i]) / S[i];
    if (H[i] > score) return false;
  }

  sort(ALL(limits));

  REP(i, N) {
    if (limits[i] < (ll)i) return false;
  }
  
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N)
    cin >> H[i] >> S[i];

  ll lb = -1;
  ll ub = 1e16 + 1;
  
  while(ub - lb > 1) {
    // OK(true);
    ll mid = (lb + ub) / 2;
    if (check(mid)) ub = mid;
    else lb = mid;
  }

  ll ans = ub;

  cout << ans << endl;

  return 0;
}

