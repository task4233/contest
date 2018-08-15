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
const int MAX_N = 77;

ll nCr[MAX_N + 1][MAX_N + 1];

void getnCr(ll n) {
  // nCnとnC0を1で初期化
  REP(i, n + 1) {
    nCr[i][0] = nCr[i][i] = 1ll;
  }

  // nCr = n-1Cr-1 + n-1Cr
  REP(i, n + 1) {
    REP(j, i) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
  }
}

int main()
{

  ll N, A, B;
  cin >> N >> A >> B;
  vector< ll > v(N);
  map< ll, ll > mp;
  REP(i, N) {
    cin >> v[i];
    mp[v[i]]++;
  }

  // 降順にソート
  sort(ALL(v));
  reverse(ALL(v));
  
  long double ans = 0.0;
  REP(i, A) {
    ans += v[i];
    // debug(ans);
  }
  // debug(ans);
  ans /= (long double)A;

  // debug(ans);
  printf("%.10Lf\n", ans);
  // cout << ans << endl;

  ll r = 0ll;
  REP(i, A) {
    if (v[i] == v[A - 1]) r++;
  }
  
  
  getnCr(MAX_N);
  // debug(n);
  // debug(r);
  ll ans2 = 0ll;

  if (r == A) {
    // 全部同じ
    FOR (i, A, B + 1) {
      ans2 += nCr[mp[v[A - 1]]][i];
    }
  } else {
    //FOR(i, 1, A - r + 1) {
      // debug(mp[v[A - 1]]);
      // debug(i);
      ans2 += nCr[mp[v[A - 1]]][r];
      //}
  }
  cout << ans2 << endl;
  
  return 0;
}

