// ------------------------------------
// Date:2018/ 3/13
// Problem:Colorfu; Leaderboard . e.cpp
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

static const int MOD = 1000000007;

bool state[8];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  memset(state, false, sizeof(state));
  vector< int > A(N);
  REP(i, N) {
    cin >> A[i];
  }
  
  int cnt = 0;
  REP(i, N) {
    if (   1 <= A[i] and A[i] <  400) state[0] = true;
    if ( 400 <= A[i] and A[i] <  800) state[1] = true;
    if ( 800 <= A[i] and A[i] < 1200) state[2] = true;
    if (1200 <= A[i] and A[i] < 1600) state[3] = true;
    if (1600 <= A[i] and A[i] < 2000) state[4] = true;
    if (2000 <= A[i] and A[i] < 2400) state[5] = true;
    if (2400 <= A[i] and A[i] < 2800) state[6] = true;
    if (2800 <= A[i] and A[i] < 3200) state[7] = true;
    if (3200 <= A[i]) cnt++;
  }

  int ansMin = 0, ansMax = 0;
  REP(i, 8) if (state[i]) ansMin++;
  if (ansMin == 0) {
    ansMin = 1;
    ansMax = cnt;
  } else ansMax = ansMin + cnt;
  cout << ansMin << " " << ansMax << endl;
  
  return 0;
}

