// ------------------------------------
// Date:2018/ 2/21
// Problem:ARC 004 _ b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) a.begin(), a.end()

typedef long long  ll;

int main()
{
  int N;
  cin >> N;
  vector< ll > d(N);
  REP(i, N) {
    cin >> d[i];
  }

  sort(ALL(d));
  
  ll big;
  ll small;
  big = 0ll;
  REP(i, N) {
    big += d[i];
  }
  
  if (N > 3) small = 0;
  else {
    if (N == 1) {
      small = d[0];
    } else if (N == 2) {
      small = d[1] - d[0];
    } else if (N == 3) {
      if (d[2] > d[0] + d[1]) {
	small = d[2] - d[1] - d[0];
      } else {
	small = 0;
      }
    }
  }

  cout << big << endl;
  cout << small << endl;
  
  return 0;
}

