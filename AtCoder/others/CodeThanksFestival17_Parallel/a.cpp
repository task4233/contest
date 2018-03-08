// ------------------------------------
// Date:2018/ 3/ 8
// Problem:CodeThanksFestival(Parallel) '17 TimePenalty a.cpp
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

static const int INF = 1000000001;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  int ans = -INF;
  REP(i, 8) {
    cin >> t;
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}

