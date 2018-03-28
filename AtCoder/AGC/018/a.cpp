// ------------------------------------
// Date:2018/ 3/20
// Problem:A- Getting Difference a.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int N, K;

bool solve(vector< int > s)
{
  if (K > s[s.size() - 1]) return false;
  REP(i, s.size()) if (K == s[i]) return true;
  REP(i, s.size() - 1) {
    if (s[i + 1] - s[i] == 1) return true;
  }
  REP(i, s.size()) {
    
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K;
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
  }
  sort(ALL(a));

  bool ok = solve(a);

  OK(ok);

  return 0;
}

