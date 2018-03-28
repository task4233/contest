// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 090 . b.cpp
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

bool check(int i) {
  string tmp = to_string(i);
  // cout << tmp << endl;
  REP(ti, tmp.size()) {
    if (tmp[ti] != tmp[tmp.size() - ti - 1]) return false;
  }
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  int cnt = 0;
  cin >> a >> b;
  FOR(i, a, b + 1) {
    if (check(i)) cnt++;
  }
  
  cout << cnt << endl;
  
  return 0;
}

