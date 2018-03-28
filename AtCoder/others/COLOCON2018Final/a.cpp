// ------------------------------------
// Date:2018/ 3/16
// Problem:COLOCON'18 Final ファイティング・タカハシ a.cpp
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

  int N;
  cin >> N;
  string s;
  cin >> s;

  int num = 0;
  ll ans = 0ll;
  while(s[num++] == 'A' and num < s.size()) {
    ans += num;
  }
  // debug(ans);
  if (num == s.size()) {
    ans = (1 + s.size() * N) * (s.size() * N) / 2;
  } else {
    int tmp2 = num;
    char tlast = s[num];
    ll tt = 0;
    ll tcnt = 0;
    FOR(ni, num + 1, s.size()) {
      if (tlast == 'A') {
	tcnt += tt + 1;
	if (s[ni] == 'A') tt++;
	else tt = 0;
      }
      tlast = s[ni];
    }
    if (tt > 0) tcnt += tt + 1;
    ans += tcnt;
    // debug(ans);
    string tmp = s.substr(num, s.size() - num);
    tmp += s.substr(0, num);
    // debug(tmp);
    ll cnt = 0;
    ll t = 0;
    char last = tmp[0];
    FOR(ti, 1, tmp.size()) {
      if (last == 'A') {
	cnt += t + 1;
	if (tmp[ti] == 'A') {
	  t++;
	} else {
	  t = 0;
	}
      }
      last = tmp[ti];
    }
    if (t > 0) cnt += t + 1;
    ans += cnt * (N - 1);
  }
  
  cout << ans << endl;
  
  return 0;
}

