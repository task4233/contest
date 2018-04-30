// ------------------------------------
// Date:2018/ 4/28
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 333;

int N;
ll memo[MAX_N][MAX_N];

ll nCr(ll n, ll r)
{
  if (r == 0 || n == r) return 1;
  if (memo[n][r] >= 0) return memo[n][r];
  return memo[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
  // return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(memo, -1, sizeof(memo));
  
  cin >> N;
  vector< string > s(N);
  vector< int > cnt(26, 0);
  REP(i, N) {
    cin >> s[i];
  }

  bool check = true;
  char ch = s[0][0];
  REP(hi, N) {
    REP(wi, N) {
      cnt[s[hi][wi] - 97]++;
      {
	if (ch != s[hi][wi]) check = false;
	ch = s[hi][wi];
      }
    }
  }

  if (check) {
    cout << N * N << endl;
    return 0;
  }

  ll ans = 0ll;
  ll tmp = N;
  sort(ALL(cnt));

  ll sum = 0ll;
  RREP(i, 26) {
    if (cnt[i] & 1) {
      sum++;
    }
  }
  debug(sum);

  RREP(i, 26) {
    if (i == 25 && sum < N) {
      continue;
    }
    if (cnt[i] < 1) break;
    if (cnt[i] & 1) {
      if (ans == 0) ans = tmp;
      else ans *= tmp;
      tmp--;
    }
  }
  if (sum < N) {
    int p = 0;
    REP(i, 26) {
      if (cnt[i] > 0) p++;
    }
    if (ans == 0) ans = p;
    else ans *= p;
  }
  
  if (sum > N || sum % 2 != N % 2) {
    // 作れない
    cout << 0 << endl;
    return 0;
  }
  // OK(true);
  debug(ans);
  tmp = N;
  RREP(i, 26) {
    if (cnt[i] < 1) break;
    if (cnt[i] & 1) {
      cnt[i]--;
      tmp--;
    }
  }

  // debug(ans);

  // ll tmp2 = (N - 1) * N / 2 + (tmp / 2);
  // debug(tmp);
  // debug(tmp2);
  FOR(h, 1, N) {
    int tmp2 = h;
    debug(ans);
    RREP(i, 26) {
      if (cnt[i] < 1) break;
      debug(i);
      debug(cnt[i]);
      // debug(nCr(tmp2, cnt[i] / 2));
      if (cnt[i] / 2 >= tmp2) { 
	if (ans == 0) ans = tmp2;
	else ans *= tmp2;
	cnt[i] -= tmp2;
      } else {
	if (ans == 0) ans = nCr(tmp2, cnt[i] / 2);
	else ans *= nCr(tmp2, cnt[i] / 2);
	tmp2 -= cnt[i] / 2;
	cnt[i] = 0;
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

