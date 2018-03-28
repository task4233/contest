// ------------------------------------
// Date:2018/ 3/17
// Problem:Otoshidama jfdklasj fdas a.cpp
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

  ll N, Y;
  cin >> N >>  Y;
  Y /= 1000;
  bool ok = false;
  
  REP(i, N + 1) {
    REP(j, N - i + 1) {
      if (10 * i + 5 * j + (N - i - j) == Y) {
	ok = true;
	cout << i << " " << j << " " << (N - i - j) << endl;
	return 0;
      }
    }
  }

  if (!ok) cout << "-1 -1 -1" << endl;
  
  return 0;
}

