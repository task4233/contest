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

static const int MOD = 1000000007;

int dx[4] = { 1, 0,-1, 0};
int dy[4] = { 0, 1, 0,-1};

// memo{x, y, dist}
tuple< int, int, int > memo[8010];

// dist: 0:+x, 1:+y, 2:-x, 3:-y

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string inputStr;
  cin >> inputStr;
  int x, y, mx, my, dist, xCnt, yCnt;
  bool flag = true;
  cin >> x >> y;

  memo[0] = make_tuple(0, 0, 0);

  xCnt = yCnt = 0;
  REP(si, inputStr.size()) {
    tie(mx, my, dist) = memo[si];
    /*
    if (mx == x && my == y) {
      if (flag) {
	if (inputStr[si] == 'F') {
	  if (dist % 2 == 0) xCnt += dx[dist];
	  else              yCnt += dy[dist];
	} else {
	  flag = false;
	  ++dist;
	}
	memo[si + 1] = make_tuple(x, y, dist);
      } else {
	if (inputStr[si] == 'F') {
	  if (dist % 2 == 0) {
	    if (xCnt >= 0) --xCnt;
	    else ++xCnt;
	  } else {
	    if (yCnt >= 0) --yCnt;
	    else ++yCnt;
	  }
	} else {
	  dist++;
	}
      }
    }
    */
    switch(inputStr[si]) {
    case 'F':
      // 今向いている向きに1だけ進む
      memo[si + 1] = make_tuple(mx + dx[dist], my + dy[dist], dist);
      break;
    case 'T':
      // rotate (clockwise or anti-clockwise)
      if (dist % 2 == 0) {
	// y方向のみ
	if (y - my >= 0) dist = 1;
	else             dist = 3;
      } else {
	// x方向のみ
	if (x - mx >= 0) dist = 0;
	else             dist = 2;
      }
      memo[si + 1] = make_tuple(mx, my, dist);
      break;
    }
  }
  
  bool ok = false;
  tie(mx, my, dist) = memo[inputStr.size()];
  if (mx == x and my == y and xCnt == 0 and yCnt == 0) ok = true;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

