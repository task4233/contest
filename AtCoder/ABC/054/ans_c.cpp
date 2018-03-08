// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 054 OneStrokePath c.cpp
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

int N, M;
int a[30];
int b[30];
bool line[8][8];

int p[10];

int main()
{
  memset(line, false, sizeof(line));
  int s,t;
  cin >> N >> M;
  REP(i, M) {
    cin >> s >> t;
    --s;
    --t;
    a[i] = s;
    b[i] = t;
    line[s][t] = true;
    line[t][s] = true;
  }
  //cout << "ok1" << endl;
  
  int cnt = 0;
  bool ok;
  REP(i, N) p[i] = i;
  //cout << "ok2" << endl;
  do {
    ok = true;
    if (p[0] != 0) continue;
    REP(i, N) {
      if (!line[p[i]][p[i + 1]]) ok = false;
      if (ok && i == N - 2) ++cnt;
    }
  } while(next_permutation(p, p+N));
  cout << cnt << endl;
  return 0;
}

