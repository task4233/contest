// ------------------------------------
// Date:2018/ 3/27
// Problem:B - 駐車場 re_h.cpp
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

int N, M, S;
vector< int > e[MAX_N];
vector< bool > state(MAX_N, false);

bool bfs(int i) {
  queue< int > q;
  vector< bool > mState(state);
  q.push(S);

  while(!q.empty()) {
    int from = q.front();
    q.pop();
    if (mState[from]) continue;
    mState[from] = true;
    if (from == i) return true;
    EACH(to, e[from]) {
      if (from < to) continue;
      q.push(to);
    }
  }
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M >> S;
  S--;

  REP(i, M) {
    CIN(a, b);
    e[a - 1].emplace_back(b - 1);
    e[b - 1].emplace_back(a - 1);
  }

  vector< int > ans;
  REP(i, N) {
    if (bfs(i)) {
      ans.emplace_back(i + 1);
      state[i] = true;
    }
  }

  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }

  return 0;
}

