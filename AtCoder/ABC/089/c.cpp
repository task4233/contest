// ------------------------------------
// Date:2018/ 3/ 4
// Problem:ABC 089 _ c.cpp
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

typedef unsigned long long ll;

static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;
  cin >> N;
  string str;
  //vector< pair< ll, bool > > cnt(5, {0ll, false});
  
  vector< ll > cnt(5, 0ll);
  //bool state[5];
  REP(i, N) {
    cin >> str;
    switch(str[0]) {
      case 'M':
        cnt[0] += 1;
        break;
      case 'A':
        cnt[1] += 1;
        break;
      case 'R':
        cnt[2] += 1;
        break;
      case 'C':
        cnt[3] += 1;
        break;
      case 'H':
        cnt[4] += 1;
        break;
    }
  }
  
  // 大きい順にソート
  sort(cnt.begin(), cnt.end(), [](ll x, ll y) {
    return x >= y;
  });
  
  ll ans = 0, sum, tmp;
  REP(i, 5) {
    sum = 0;
    if (cnt[i] == 0) continue;
    FOR(j, i + 1, 5) {
      tmp = 0;
      if (cnt[j] == 0) continue;
      // state[j] == trueのとき
      FOR(k, j + 1, 5) {
        if (cnt[k] == 0) continue;
        tmp += cnt[k];
        //debug(i);
        //debug(j);
        //debug(k);
      }
      sum += tmp * cnt[j];
    }
    if (cnt[i] != 0) ans += sum * cnt[i];
  }
  
  cout << ans << endl;
  
  return 0;
}

