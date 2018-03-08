// ------------------------------------
// Date:2018/ 2/26
// Problem:ABC 051 CandidatesOfNoShortestPaths re_d.cpp
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

int main()
{
  int N,M,cnt = 0;
  cin >> N >> M;
  vector< vector<int> > line(N, vector<int> (N,1e4));
  vector<int> a(M);
  vector<int> b(M);
  vector<int> c(M);
  REP(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    line[--a[i]][--b[i]] = c[i];
    line[b[i]][a[i]] = c[i];
  }
  
  // Warshall-Floyd
  REP(h,N) {
    REP(i,N) {
      REP(j,N) {
        line[i][j] = min(line[i][j], line[i][h] + line[h][j]);
      }
    }
  }
  
  REP(i,M) {
    if (line[a[i]][b[i]] < c[i]) ++cnt;
  }
  cout << cnt << endl;
  return 0;
}

