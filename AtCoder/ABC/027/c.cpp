
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
ll memo[MAX_N];

ll power(ll x, int n)
{
  if (memo[n] > -1) return memo[n];

  int t = n;
  ll res = 1;
  while(n > 0) {
    if (n & 1) {
      res *= x;
    }
    x *= x;
    n >>= 1;
  }

  return memo[t] = res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  string ans;

  memset(memo, -1, sizeof(memo));
  
  if (N == 1) {
    cout <<  "Aoki" << endl;
    return 0;
  }
  
  REP(i, MAX_N) {
    if (power(2, i + 1) > N) {
      if (i & 1) {
	ans = "Takahashi";
      } else {
	ans = "Aoki";
      }
      if (!ans.empty()) break;
    }
  }

  cout << ans << endl;
  
  return 0;
}

