// ------------------------------------
// Date:2018/ 3/12
// Problem:ABC 073 WriteAndErase c.cpp
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

// static const int MOD = 1000000007;
// static const int MAX_N = 1010101010;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  set< int > SI;
  REP(i, N) {
    int a;
    cin >> a;
    a--;
    if (SI.erase(a) == 0) SI.insert(a);
  }

  int ans = SI.size();
  cout << ans << endl;
  
  return 0;
}

