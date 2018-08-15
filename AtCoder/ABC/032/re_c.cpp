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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, K);
  vector< ll > S(N);
  bool ok = false;
  bool ng = true;
  REP(i, N) {
    cin >> S[i];
    // 0が1つでも含まレている時の答えはN
    ok |= (S[i] == 0);
    // 全てKより大きい時の答えは0
    ng &= (S[i] > K);
  }
  if (ok){
    cout << N << endl;
    return 0;
  }
  if (ng) {
    cout << 0 << endl;
    return 0;
  }
  
  
  ll tmp = 1ll;
  int ans = 0;
  int ub = 0;
  REP(lb, N) {
    ub = max(ub, lb);
    while (ub < N && tmp * S[ub] <= K) {
      // 掛け合わせてKより大きい時はスルー
      tmp *= S[ub++];
    }
    ans = max(ans, ub - lb);
    if (lb == ub) ub++;
    else tmp /= S[lb];
  }

  cout << ans << endl;

  return 0;
}

