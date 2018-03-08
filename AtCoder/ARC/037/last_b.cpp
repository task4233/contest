// ------------------------------------
// Date:2018/ 2/27
// Problem:ARC 037 バウムテスト b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

int N, M;
bool state[101];
// line[from][to]
bool line[101][101];

int main()
{
  cin >> N >> M;
  vector< int > u(M);
  vector< int > v(M);
  memset(state, false, sizeof(state));
  memset(line, false, sizeof(line));
  REP(i, M) {
    cin >> u[i] >> v[i];
    --u[i];
    --v[i];
    line[u[i]][v[i]] = true;
    line[v[i]][u[i]] = true;
  }
  
  // 1つの頂点から深さ優先探索
  // 通ったらstate->trueに
  int ans = 0;
  bool through;
  REP(i, N) {
    through = false;
    if (state[i]) continue;
    queue< int > q;
    q.push(i);
    while(!q.empty()) {
      int from = q.front();
      //cout << from << "->";
      state[i] = true;
      q.pop();
      REP(to, N) {
        if (line[from][to]) {
          // 閉路ができるとき
          if (state[to]) {
            if (!through && from < to) {
              //--ans;
              through = true;
            }
          } else {
            state[to] = true;
            q.push(to);
          }
        }
      }
    }
    if (!through) ++ans;
  }
  
  cout << ans << endl;
  return 0;
}

