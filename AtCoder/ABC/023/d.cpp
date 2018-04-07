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

// dp[N個のデータ]
ll dp[MAX_N];

typedef pair< ll, int > PLI;

int N;
ll H[MAX_N], S[MAX_N];

bool check(ll xi)
{
  vector< ll > limit(N);
  REP(i, N) {
    if (xi < H[i]) return false;
    limit[i] = (xi - H[i]) / S[i];
  }
  sort(ALL(limit));
  REP(i, N)
    if (limit[i] < ll(i)) return false;
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  
  ll lb = 0ll;
  ll ub = 1e18;
  REP(i, N) {
    cin >> H[i] >> S[i];
    // lb = max(lb, H[i]);
    // ub = max(ub, H[i] + S[i] * N);
  }

  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (check(mid)) ub = mid;
    else lb = mid;
  }
  
  ll ans = ub;
  
  cout << ans << endl;
  
  return 0;
}

