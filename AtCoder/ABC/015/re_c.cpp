#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Found" : "Nothing") << endl;
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
const int MAX_N = 575;

int N, K;
int T[MAX_N][MAX_N];

bool dfs(int n, int xorSum)
{
  if (n == N) {
    return xorSum == 0;
  }

  REP(i, K) {
    if (dfs(n + 1, xorSum ^ T[n][i])) {
      return true;
    }
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;

  REP(i, N) {
    REP(j, K) {
      cin >> T[i][j];
    }
  }

  OK(dfs(0, 0));
  
  return 0;
}

