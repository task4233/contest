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

ll fact[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fact[1] = 1ll;
  REP(i, MAX_N - 2) {
    (fact[i + 2] += fact[i + 1]) %= MOD;
    (fact[i + 2] += fact[i + 1]) %= MOD;
    (fact[i + 2] += fact[i + 1]) %= MOD;
  }

  debug(fact[3]);
  debug(fact[4]);
  
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
    ll pa = d[si][0];
    ll pc = d[si - 1][3];
    ll qa = d[S.size() - 1][2] - d[si][2];
    ll qc = d[S.size() - 1][3] - d[si][3];
    if (S[si] == 'B' || S[si] == '?') {
      
      ans += (pa + fact[pc]) * (qa + fact[qc]);
      ans %= MOD;
      debug(ans);
      ans += fact[pc - 1]  * (qa + fact[qc]) + 1;
      ans %= MOD;
      debug(ans);
      ans += (pa + fact[pc]) * fact[qc - 1] + 1;
      ans %= MOD;
      // ans -= pa * qa;
      debug(ans);
      ans += fact[(pc + qc)] - 2;
      // ans %= MOD;
      // +(d[si][0] + d[si - 1][3]) * (d[S.size() - 1][2] - d[si][2] + d[S.size() - 1][3] - d[si][3]);
    } //else if (S[si] == '?') {
      //ans += (d[si][0] + d[si - 1][3]) * (d[S.size() - 1][2] - d[si][2] + d[S.size() - 1][3] - d[si][3]);
    // }
    ans %= MOD;
    debug(si);
    debug(ans);
  }

  cout << ans << endl;

  

  return 0;
}

