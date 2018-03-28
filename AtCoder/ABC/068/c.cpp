// ------------------------------------
// Date:2018/ 3/13
// Problem:ABC 068 CatSnukeAndAVoyage c.cpp
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
  
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  set< int > a;
  queue< int > q; 
  REP(i, M) {
    int x, y;
    cin >> x >> y;
    if (x == 1) q.push(y);
    if (y == N) {
      if (!a.erase(x)) a.insert(x);
    }
  }

  bool ok = false;
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    if (a.count(from)) ok = true;
    if (ok) break;
  }

  cout << (ok ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  
  return 0;
}

