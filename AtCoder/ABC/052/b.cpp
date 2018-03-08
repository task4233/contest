// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 052 IncrementDecrement b.cpp
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
  int N, ans = 0;
  string S;
  cin >> N;
  cin >> S;
  int x = 0;
  REP(i, S.size()) {
    if (S[i] == 'I') ++x;
    else             --x;
    ans = max(x, ans);
  }
  cout << ans << endl;
  return 0;
}

