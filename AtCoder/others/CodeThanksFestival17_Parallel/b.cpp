// ------------------------------------
// Date:2018/ 3/ 8
// Problem:CodeThanksFestival(Parallel) '17 ConcatenatedPalindrome b.cpp
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
  int mSize = s.size();
  bool ok = false;
  int ans;
  
  REP(i, mSize) {
    REP(j, s.size()) {
      if (not(s[j] == s[s.size() - 1 - j] or s[s.size() - 1 - j] == '*' or s[j] == '*')) {
	break;
      }
      if (j == s.size() - 1) ok = true;
    }
    if (ok) {
      ans = i;
      break;
    }
    // *は任意の文字として扱う
    s += "*";
  }

  cout << ans << endl;
  return 0;
}

