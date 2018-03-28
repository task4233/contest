// ------------------------------------
// Date:2018/ 3/14
// Problem:dowango04 preliminary 2525文字列分解 b.cpp
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

  string s;
  cin >> s;

  int ans, t, tf, cnt;
  t = tf = ans = cnt = 0;
  bool ng = false;
  REP(si, s.size()) {
    if (s[si] == '5') {
      if (t == 0) ng = true;
      t--;
      tf++;
    }
    if (s[si] == '2') {
      if (tf > 0) {
	tf--;
      } else {
	cnt++;
      }
      t++;
    }
  }
  

  if (t > 0) ng = true;
  if (ng) ans = -1;
  else ans = tf;

  cout << ans << endl;
  
  return 0;
}

