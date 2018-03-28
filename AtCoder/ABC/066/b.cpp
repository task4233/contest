// ------------------------------------
// Date:2018/ 3/15
// Problem:ABC 066 ss b.cpp
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
  bool ok;
  int ans = 0;
  for (int i = 0; i < (s.size() + 1) / 2; ++i) {
    ok = false;
    for (int j = 0; j < i; ++j) {
      if (s[j] != s[i + j]) break;
      if (j == i - 1) ok = true;
    }
    if (ok) ans = i;
  }
  
  cout << ans * 2 << endl;
  
  return 0;
}

