// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 021 Tiling c.cpp
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

//dp[今見ているところ][残りのタイル数]


int main()
{
  char Board[1000][1000];
  int N,M,A,B;
  cin >> N >> M;
  cin >> A >> B;
  REP(ni,N) {
    REP(nj,M) {
      Board[ni][nj] = '.';
    }
  }
  REP(ni,N) {
    REP(nj,M) {
      if (Board[ni][nj] == '.') {
        if (A > 0 && ni < N-1) {
          Board[ni][nj] = '<';
          Board[ni+1][nj] = '>';
          --A;
        } else if (B > 0 && ni < M-1) {
          Board[ni][nj] = '^';
          Board[ni][nj+1] = 'v';
          --B;
        }
      }
      if (ni == N-1 && nj == M-1 && A != 0 && B != 0) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  REP(i,N) {
    REP(j,M) {
      cout << Board[i][j];
    }
    cout << endl;
  }
  return 0;
}

