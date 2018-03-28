// ------------------------------------
// Date:2018/ 3/ 9
// Problem:ABC 062 PictureFrame b.cpp
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

  char ch;
  int H, W;
  cin >> H >> W;

  REP(hi, H + 2) {
    REP(wi, W + 2) {
      if (hi == 0 or hi == H + 1 or wi == 0 or wi == W + 1) {
	cout << '#';
      } else {
	cin >> ch;
	cout << ch;
      }
    }
    cout << endl;
  }

  
  return 0;
}

