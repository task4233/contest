// ------------------------------------
// Date:2018/ 3/29
// Problem:_ _ _ a.cpp
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
#define OK(ok) cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
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

int N, M;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  set< int > a;
  set< int > b;
  REP(i, M) {
    CIN(p, q);
    if (p == 1) a.insert(q);
    if (q == 1) a.insert(p);
    if (p == N) b.insert(q);
    if (q == N) b.insert(p);
  }

  bool ok = false;
  EACH(ai, a) {
    if (b.find(ai) != b.end()) {
      ok = true;
      break;
    }
  }
  OK(ok);
  
  return 0;
}

