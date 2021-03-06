// ------------------------------------
// Date:2018/ 3/ 5
// Problem:ABC 083 WideFlip d.cpp
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

  string inputStr;
  cin >> inputStr;
  int len = inputStr.size();
  int ans = len;
  REP(i, len - 1) {
    if (inputStr[i] != inputStr[i + 1]) {
      // ここでmax(i + 1, len - i - 1)の区間で反転をすることにより、全ての数字を同じにすることができる
      ans = min(ans, max(i + 1, len - i - 1));
    }
  }
  cout << ans << endl;
  return 0;
}

