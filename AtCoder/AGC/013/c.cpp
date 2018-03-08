// ------------------------------------
// Date:2018/ 2/26
// Problem:AGC 013 AntsOnACircle c.cpp
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

using ll = long long;

#define MOD 1000000007

int main()
{
  int N,L,T;
  cin >> N >> L >> T;
  vector<int> X(N);
  vector<int> W(N);
  REP(i,N) {
    cin >> X[i] >> W[i];
  }
  int diff = 0;
  REP(i,N) {
    if (W[i] == 1) {
      // clockwise
      diff += (X[i] + T) / L;
      X[i] += T;
      X[i] %= L;
    } else {
      // anti-clockwise
      diff -= (T - X[i] + L - 1)/L;
      X[i] -= T;
      X[i] = (X[i]%L+L)%+L;
    }
  }
  sort(ALL(X));
  diff = (diff % N + N) % N;
  REP(i,N) {
    cout << X[(diff + i) % N] << endl;
  }
  return 0;
}
