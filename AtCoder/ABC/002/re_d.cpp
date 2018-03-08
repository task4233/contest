// ------------------------------------
// Date:2018/ 2/27
// Problem:ABC 002 派閥 d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

bool connection[12][12];

int main()
{
  int N,M;
  cin >> N >> M;
  vector< int > x(M);
  vector< int > y(M);
  REP(i, M) {
    cin >> x[i] >> y[i];
  }
  
  int ans = 1;
  bool ok;
  memset(connection, false, sizeof(connection));
  
  REP(i, M) {
    connection[x[i]-1][y[i]-1] = true;
    connection[y[i]-1][x[i]-1] = true;
  }
  
  FOR(bit, 1, (1 << N)) {
    // tmpはbitのうち1の部分が繋がれる人数
    int makableNum = bitset<12>(bit).count();
    if (makableNum <= ans) continue;
    ok = true;
    REP(i, N) {
      REP(j, i) {
        // iとjのつながりがないが、自分とのつながりがあるものを外す
        if (connection[i][j] == false &&
            (bit >> i & bit >> j & 1)) {
          ok = false;
        }
      }
    }
    if (ok) ans = makableNum;
  }
  cout << ans << endl;
  return 0;
}

