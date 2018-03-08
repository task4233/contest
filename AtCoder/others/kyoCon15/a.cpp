// ------------------------------------
// Date:2018/ 3/ 3
// Problem:kyoCon '15 東京都 a.cpp
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
  
  int T;
  cin >> T;
  vector< string > S(T);
  REP(i, T) {
    cin >> S[i];
  }
  
  int ans;
  string tmp;
  REP(i, T) {
    ans = 0;
    REP(j, S[i].size() - 4) {
      tmp = S[i].substr(j,5);
      if (tmp == "kyoto" or tmp == "tokyo") {
        ++ans;
        j += 4;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

