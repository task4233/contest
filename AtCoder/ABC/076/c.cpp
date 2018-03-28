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
  int cnt = 0;
  REP(si, s.size() - t.size() + 1) {
    flag = true;
    REP(ti, t.size()) {
      if (not(s[si + ti] == t[ti] or s[si + ti] == '?')) flag = false;
    }
    if (flag) {
      cnt = si;
      ok = true;
    }
  }
  REP(ti, t.size()) {
    s[ti + cnt] = t[ti];
  }
  REP(si, s.size()) {
    if (s[si] == '?') {
      s[si] = 'a';
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

