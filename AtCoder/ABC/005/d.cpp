// ------------------------------------
// Date:2018/ 2/17
// Problem:ABC 005 oishiitakoyakinoyakikata d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

// N:一辺の長さ / D:おいしさ / Q:店員の人数 / P:それぞれの店員が焼ける個数

int N;
int Q;
int D[55][55];
int P[3025];
int sum[55][55];
int dp[3025] = {0};

int main()
{
  cin >> N;
  REP(i,N) REP(j,N) cin >> D[i][j];
  cin >> Q;
  REP(i,Q) cin >> P[i];
  REP(j,N) sum[0][j] = 0;
  
  FOR(i,1,N+1) {
    int res = 0;
    sum[i][0] = 0;
    FOR(j,1,N+1) {
      res += D[i-1][j-1];
      sum[i][j] = sum[i-1][j] + res;
    }
  }
  
  REP(i,N+1) {
    REP(j,N+1) {
      REP(x,N-i+1) {
        REP(y,N-j+1) {
          dp[i*j] = max(sum[i+x][j+y] - sum[i+x][y] - sum[x][j+y] + sum[x][y], dp[i*j]);
        }
      }
    }
  }
  REP(i,3025) {
    if (i>=1) dp[i] = max(dp[i], dp[i-1]);
  }
  REP(i,Q) {
    cout << dp[P[i]] << endl;
  }
  
  return 0;
}

