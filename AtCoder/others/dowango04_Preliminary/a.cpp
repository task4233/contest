// ------------------------------------
// Date:2018/ 3/14
// Problem:dowango04 preliminary ニコニコ文字列判定 a.cpp
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
  bool ok = false;
  if (s[0] == s[2] and s[1] == s[3]) ok = true;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

