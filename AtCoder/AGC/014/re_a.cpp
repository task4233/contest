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

int A, B, C;

ll dfs(int A, int B, int C)
{
  ll res = 0ll;
  if ((A & 1) || (B & 1) || (C & 1)) return 0;
  int nextA = (B >> 1) + (C >> 1);
  int nextB = (A >> 1) + (C >> 1);
  int nextC = (A >> 1) + (B >> 1);

  res += dfs(nextA, nextB, nextC);

  return res + 1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> A >> B >> C;

  if (A == B && B == C && A != 1) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = dfs(A, B, C);
  cout << ans << endl; 

  return 0;
}

