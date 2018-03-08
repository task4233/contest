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
bool line[8][8];
int p[8];

int main()
{
  memset(line , false, sizeof(line));
  int s,t;
  cin >> N >> M;
  REP(i, M) {
    cin >> s >> t;
    --s;
    --t;
    line[s][t] = true;
    line[t][s] = true;
  }
  
  REP(i, N) p[i] = i;
  
  bool ok;
  int cnt = 0;
  do {
    ok = true;
    // 始点が0以外はスルーする
    if (p[0] != 0) continue;
    REP(i, N - 1) {
      if (!line[p[i]][p[i+1]]) ok = false;
      if (ok && i == N - 2) ++cnt;
    }
  } while(next_permutation(p, p+N)); // 辞書式配列に並べ換えるライブラリ関数
  cout << cnt << endl;
  
  return 0;
}

