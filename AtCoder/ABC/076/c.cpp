// ------------------------------------
// Date:2018/ 3/ 7
// Problem:ABC 076 DubioutsDocument2 c.cpp
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

  string s, t, tmp;
  cin >> s >> t;

  bool ok = false;
  bool flag;
  int cnt;
  REP(si, s.size()) {
    REP(ti, t.size()) {
      if (flag) {
	if ((s[si] == t[ti] or s[si] == '?') and ti == t.size() - 1) {
	  REP(tj, t.size()) {
	    s[si + tj] = t[tj];
	  }
	  ok = true;
	}
	if (!(s[si] == t[ti] or s[si] == '?')) flag = false;
      } else {
	if (s[si] == t[ti]) {
	  flag = true;
	}
      }
    }
  }

  string ans;
  if (!ok) {
    ans = "UNRESTORABLE";
  } else {
    ans = s;
  }
  cout << ans << endl;
  return 0;
}

