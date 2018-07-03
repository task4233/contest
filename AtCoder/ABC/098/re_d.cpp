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
const int MAX_N = 2e5 + 1;

ll N;
ll A[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  bool zero_flag = true;
  cin >> N;
  REP(i, N) {
    cin >> A[i];
    if (A[i] != 0) zero_flag = false;
    // bitset< 4 > a(A[i]);
    // debug(a);
  }

  if (zero_flag) {
    cout << N * (N + 1) / 2 << endl;
    return 0;
  }

  ll ans = 0ll;
  int ub = 0;
  ll sm = 0ll;
  REP(lb, N) {
    if (lb == ub) {
      sm += A[lb];
    }
    ub = max(lb + 1, ub);

    while (ub < N) {
      if (sm + A[ub] > (sm xor A[ub])) break;

      sm += A[ub];
      ub++;
    }
    ans += ub - lb;
    sm -= A[lb];
    /*
    debug(sm);
    debug(ans);
    debug(lb);
    debug(ub);
    cout << endl;
    */
  }

  cout << ans << endl;
  

  return 0;
}

