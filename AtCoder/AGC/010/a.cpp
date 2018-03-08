// ------------------------------------
// Date:2018/ 3/ 8
// Problem:AGC 010 Addition a.cpp
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

  int N;
  cin >> N;
  int cnt = 0;
  int tmp;
  REP(i, N) {
    cin >> tmp;
    if (tmp % 2 == 1) {
      ++cnt;
    }
  }

  cout << (cnt % 2 == 0 ? "YES" : "NO") << endl;
  
  return 0;
}

