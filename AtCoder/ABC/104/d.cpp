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
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

string S;

// 0:a 1:b 2:c 3:?
ll d[MAX_N][4];

ll power(ll p, ll q) {
  ll res = 1ll;
  while (q > 0) {
    if ((q & 1) == 1) {
      (res *= p) %= MOD;
    }
    (p *= p) %= MOD;
    q >>= 1;
  }
  return res % MOD;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  
  cin >> S;
  REP(si, S.size()) {
    switch(S[si]) {
    case 'A':
      d[si][0]++;
      break;
    case 'B':
      d[si][1]++;
      break;
    case 'C':
      d[si][2]++;
      break;
    case '?':
      d[si][3]++;
      break;
    }
  }

  REP(si, S.size()) {
    REP(i, 4) {
      d[si + 1][i] += d[si][i];
    }
  }

  ll ans = 0ll;
  FOR(si, 1, S.size() - 1) {
    // 左のA
    ll la = d[si - 1][0];
    // 左の?
    ll lq = d[si - 1][3];
    // 右のC
    ll rc = d[S.size()][2] - d[si][2];
    // 右の?
    ll rq = d[S.size()][3] - d[si][3];
    // debug(la);
    // debug(lq);
    // debug(rc);
    // debug(rq);
    if (S[si] == 'B' || S[si] == '?') {
      // ABC
      (ans += la * rc * power(3ll, (lq + rq))) %= MOD;
      // AB?
      // powerの-1は,rqで?を一つ使っているから
      (ans += la * rq * power(3ll, (lq + rq - 1))) %= MOD; 
      // ?BC(同上)
      (ans += lq * rc * power(3ll, (lq + rq - 1))) %= MOD;
      // ?B?(同上)
      (ans += lq * rq * power(3ll, (lq + rq - 2))) %= MOD;
    }
    ans %= MOD;
    // debug(si);
    // debug(ans);
  }

  cout << ans << endl;

  

  return 0;
}

