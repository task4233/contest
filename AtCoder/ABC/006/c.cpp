// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 006 スフィンクスのなぞなぞ c.cpp
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
  int N, M, adultNum, oldPersonNum;
  cin >> N >> M;
  REP(babyNum, N + 1) {
    adultNum     = 3*N - M + babyNum;
    oldPersonNum = M - 2*N - 2*babyNum;
    if (adultNum >= 0 && oldPersonNum >= 0) {
      cout << adultNum << " " << oldPersonNum << " " << babyNum << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}

