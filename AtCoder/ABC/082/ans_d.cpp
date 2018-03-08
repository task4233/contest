// ------------------------------------
// Date:2018/ 3/ 5
// Problem:ABC 082 FTRobot d.cpp
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

// dpx[num][pos], dpy[num][pos] : 2.56*10^8Byte
bool dpx[8080][16010];
bool dpy[8080][16010];

inline int p(int n) { return n + 8000; }

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(dpx, false, sizeof(dpx));
  memset(dpy, false, sizeof(dpy));
  
  bool ok = false;
  string S;
  cin >> S;
  int x, y, cnt = 0, tmp;
  cin >> x >> y;
  while (S[cnt] == 'F') ++cnt;
  // cout << cnt << endl;
  tmp = cnt;
  dpx[tmp][p(tmp)] = true;
  dpy[tmp][p(0)] = true;

  
  // dist: true(x方向), false(y方向)
  bool dist = true;
  cnt = 0;
  if (tmp == 0) {
    // 1文字目がTのとき
    dist = false;
  }
  FOR(si, (tmp==0 ? 1 : tmp), S.size() + 1) {
    if (S[si] == 'T' or si == S.size()) {
      if (dist) {
	// x方向
	FOR(i, 1+abs(cnt), 16000-abs(cnt)) {
	  if (dpx[si - cnt - 1][i]) {
	    dpx[si][i + cnt] = true;
	    dpx[si][i - cnt] = true;
	    //cout << si << "," << i + cnt << (dpx[si][p(i + cnt)] ? "T" : "F") << endl;
	  }
	  if (dpy[si - cnt - 1][i]) dpy[si][i] = true;
	}
      } else {
	// y方向
	FOR(i, 1+abs(cnt), 16000-abs(cnt)) {
	  if (dpx[si - cnt - 1][i]) dpx[si][i] = true;
	  if (dpy[si - cnt - 1][i]) {
	    dpy[si][i + cnt] = true;
	    dpy[si][i - cnt] = true;
	    //cout << si << "," << i + cnt << (dpy[si][p(i + cnt)] ? "T" : "F") << endl;
	  }
	}
      }
      dist = !dist;
      cnt = 0;
    } else {
      ++cnt;
    }
  }

  /*
  REP(i, S.size() + 1) {
    FOR(j, -3, 3) {
      FOR(k, -3, 3) {
	if (dpx[i][p(j)] and dpy[i][p(k)]) cout << j << "," << k << (dpx[i][p(j)] ? "XT" : "XF") << (dpy[i][p(k)] ? "YT" : "YF") << endl;
      }
    }
    cout << i << "END" << endl;
  }
  */

  if (dpx[S.size()][p(x)] and dpy[S.size()][p(y)]) ok = true;
  
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

