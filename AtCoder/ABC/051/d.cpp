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

// --------------------------------------------
// 全点間最短経路問題
// --------------------------------------------

int main()
{
  int N,M,cnt = 0;
  cin >> N >> M;
  vector<int> a(M),b(M),c(M);
  REP(i,M) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }

  const int MAX = 9999999;
  
  // dist[from,to]がfromからtoの最短距離
  vector< vector<int> > dist(N, vector<int>(N,0));
  REP(i,N) {
    REP(j,N) {
      dist[i][j] = MAX;
    }
    dist[i][i] = 0;
  }
  
  REP(i,M) {
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = dist[a[i]][b[i]];
  }

  // Warshall Floyd
  // 中継点
  REP(k,N) {
    // 始点
    REP(i,N) {
      // 終点
      REP(j,N) {
	// min(直接行く or 中継点を通って行く)
	dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  REP(i,M) {
    if (dist[a[i]][b[i]] < c[i]) ++cnt; 
  }
  cout << cnt << endl;
  return 0;
}

