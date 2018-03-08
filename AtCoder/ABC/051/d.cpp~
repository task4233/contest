// ------------------------------------
// Date:2018/ 2/26
// Problem:ABC 052 TwoRectangles a.cpp
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

typedef long long ll;

#define MOD 1000000007

// N:頂点の数, M:辺の数
int N,M;
// Line[from][to] = weight
int Line[101][101];
// dp[to] = weight
int dp[101];
// state[from][next]は通ったか否かを格納
bool state[101][101];
int loopCnt;

int search(int from,int to)
{
  loopCnt = 0;
  queue<int> q;
  q.push(from);
  while(!q.empty()) {
    int tmp = q.front();
    debug(tmp);
    q.pop();
    if (loopCnt > 1 && tmp == to) return dp[to];
    ++loopCnt;
    REP(i,N) {
      if (state[tmp][i]) continue;
      if (Line[tmp][i] != -1) {
	state[i][tmp] = true;
	state[tmp][i] = true;
	dp[i] = dp[tmp] + Line[tmp][i];
	q.push(i);
      }
    }
  }
  return 1e4;
}

int main()
{
  int a,b,c,cnt = 0;
  cin >> N >> M;
  memset(Line,-1,sizeof(Line));
  REP(i,M) {
    cin >> a >> b >> c;
    Line[a][b] = c;
    Line[b][a] = c;
  }
  if (N <= M) {
    REP(from,N) {
      REP(to,from) {
	// 短い経路がないか探索
        if (search(from,to) <= Line[from][to]) {
	  ++cnt;
	}
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

