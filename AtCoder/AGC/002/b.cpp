// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 002 BoxAndBall b.cpp
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

using ll = long long;

#define MOD 1000000007

// box
int dp[100000];
bool ball[100000];

int main()
{
  int N,M,x,y;
  int cnt = 0;
  memset(dp,0,sizeof(dp));
  memset(ball,false,sizeof(ball));
  cin >> N >> M;
  FOR(i,1,N+2) {
    dp[i] = 1;
  }
  ball[1] = true;
  REP(i,M) {
    cin >> x >> y;
    if (ball[x]) {
      if (dp[x] == 1) {
        ball[x] = false;
      }
      ball[y] = true;
    }
    --dp[x];
    ++dp[y];
  }
  FOR(i,1,N+1) {
    //cout << i << "->" << (ball[i]?"Yes":"No") << endl;
    if (ball[i]) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}

