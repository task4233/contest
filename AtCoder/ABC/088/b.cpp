// ------------------------------------
// Date:2018/ 2/18
// Problem:ABC 088 _ b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
  int N,a,b;
  cin >> N;
  a = b = 0;
  vector <int> V(N);
  REP(i,N) {
    cin >> V[i];
  }
  sort(V.begin(),V.end());
  REP(i,V.size()) {
    if (i%2 == 0) {
      a += V[V.size()-i-1];
      //cout << a << endl;
    } else {
      b += V[V.size()-i-1];
      //cout << b << endl;
    }
  }
  cout << a-b << endl;
  return 0;
}

