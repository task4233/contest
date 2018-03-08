// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 007 辞書式順序 b.cpp
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
  string s, ans;
  cin >> s;
  if (s[0] == 'a' && s.size() == 1) ans = "-1";
  else ans = "a";
  cout << ans << endl;
  return 0;
}

