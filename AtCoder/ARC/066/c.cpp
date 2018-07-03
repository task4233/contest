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
int A[MAX_N];

ll power(ll x, ll n)
{
  ll res = 1ll;
  while(n > 0) {
    if (n & 1) (res *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }

  return res % MOD;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  map< int, int > mp;
  cin >> N;
  REP(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }

  sort(A, A + N);

  bool ok = true;
  
  REP(i, N) {
    int tmp = abs(N - i - 1);
    mp[tmp]--;
    ok &= (A[i] % 2 == (N - 1) % 2);
  }

  EACH(mi, mp) {
    if (mi.second != 0) ok = false;
  }
  
  ll ans = power(2, N / 2);
  if (!ok) ans = 0ll;

  cout << ans << endl;

  return 0;
}

