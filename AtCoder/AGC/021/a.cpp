// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 021 DigitSum2 a.cpp
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

using ll = long long;

#define MOD 1000000007

int main()
{
  string s;
  int tmp;
  bool flag = true;
  ll ans = 0ll;
  cin >> s;
  REP(i,s.size()) {
    if (s.size() == 1) {
      cout << s << endl;
      return 0;
    }
    ll tmp = s[i] - '0';
    if (i == 0) {
      ans = tmp-1;
    } else {
      ans += 9ll;
    }
    if (i != 0 && tmp != 9) flag = false;
    if (flag && i == s.size()-1) ++ans;
    //cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}

