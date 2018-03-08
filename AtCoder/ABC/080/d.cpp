// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 080 Recording d.cpp
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

// static const int MOD = 1000000007;
//static const int INF = 1e9 + 1;

// s,t[101010]
int s[101010];
int t[101010];
int c[101010];
int timetable[30][101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(timetable, 0, sizeof(timetable));
  int N, C;
  cin >> N >> C;

  // O(N)
  REP(i, N) {
    cin >> s[i] >> t[i] >> c[i];
    s[i];
    t[i];
    --c[i];
    timetable[c[i]][s[i]]++;
    timetable[c[i]][t[i]]--;
  }

  // O(CN)
  REP(h, C) {
    REP(i, 101000) {
      //debug(i);
      //debug(ans);
      //debug(timetable[h][i]);
      timetable[h][i + 1] += timetable[h][i];
    }
  }

  // O(CN)
  REP(h, C) {
    REP(i, 101010) {
      if (timetable[h][i] == 0 and timetable[h][i + 1] == 1) {
	++timetable[h][i];
      }
    }
  }
  
  int ans = 0, tmp;
  REP(i, 101010) {
    tmp = 0;
    REP(h, C) {
      tmp += timetable[h][i];
    }
    ans = max(ans, tmp);
    //debug(i)
    //debug(ans);
    //debug(timetable[i]);
  }
  cout << ans << endl;
  
  return 0;
}

