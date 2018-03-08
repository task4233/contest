// ------------------------------------
// Date:2018/ 2/16
// Problem:ABC 005 oishiitakoyakinourikata c.cpp
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
  int T,N,M,t;
  vector<int> A;
  vector<int> B;
  bool done[100];
  REP(i,100) done[i] = false;
  // たこ焼き
  cin >> T >> N;
  REP(i,N) {
    cin >> t;
    A.emplace_back(t);
  }
  // 客
  cin >> M;
  REP(i,M) {
    cin >> t;
    B.emplace_back(t);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  
  if (N<M) {
    cout << "no" << endl;
  } else {
    REP(mi,M) {
      REP(ni,N) {
        if (done[ni]) continue;
        //cout << mi << ":" << ni << "=>" << B.at(mi) << "," << A.at(ni) << "," << B.at(mi)-A.at(ni) << endl;
        if (B.at(mi)-A.at(ni)>= 0 && B.at(mi)-A.at(ni) <= T) {
          done[ni] = true;
          break;
        }
        if (ni == N-1) {
          cout << "no" << endl;
          return 0;
        }
      }
    }
    cout << "yes" << endl;
  }
  return 0;
}

