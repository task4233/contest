// ------------------------------------
// Date:2018/ 2/22
// Problem:ABC 043 BeTogether c.cpp
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
#define POW(x) (x)*(x)

using ll = long long;

int main()
{
  int N,tmp,min = 1e9;
  cin >> N;
  vector<int> a(N);
  REP(i,N) {
    cin >> a[i];
  }
  sort(ALL(a));
  if (a[0] == a[N-1]) min = 0;
  FOR (i,a[0],a[N-1]) {
    tmp = 0;
    REP(j,N) {
      tmp += POW(a[j]-i);
    }
    min = std::min(tmp,min);
  }
  cout << min << endl;
  return 0;
}

