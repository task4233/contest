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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

ll sm[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< ll > A(N);
  REP(i, N) {
    cin >> A[i];
  }

  sort(ALL(A));

  REP(i, N) {
    sm[i] = A[i];
  }

  REP(i, N) {
    sm[i + 1] += sm[i];
  }
  
  int ans = N;
  RREP(i, N - 1) {
    
    if (2ll * sm[i] < A[i + 1]) {
      ans = min(N - i - 1, ans);
      break;
    }
  }

  cout << ans << endl;

  return 0;
}

