
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
const int MAX_N = 1e4 + 1;

int N, X;
int table[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> X;
  // X--;

  REP(i, N) {
    CIN(a, b);
    table[min(a, b)]++;
    table[max(a, b) + 1]--;
  }

  REP(i, MAX_N) {
    if (i > 0) table[i] += table[i - 1];
  }

  int ans = INF;
  REP(i, 1001) {
    // debug(table[i]);
    if (table[i] > N - 1) {
      ans = min(ans, abs(i - X));
    }
  }

  if (ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}

