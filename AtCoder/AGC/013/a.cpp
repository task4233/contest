// ------------------------------------
// Date:2018/ 2/26
// Problem:AGC 013 SortedArrays a.cpp
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
  int N,last,next,state = -1,cnt = 0;
  cin >> N;
  REP(i,N) {
    cin >> next;
    if (state == -1) {
      last = next;
      state = 0;
    } else if (state == 0) {
      if (next < last) {
        state = 2;
      } else if (next > last) {
        state = 1;
      }
    } else if (state == 1) {
      if (next < last) {
        ++cnt;
        state = 0;
      }
    } else {
      if (next > last) {
        ++cnt;
        state = 0;
      }
    }
    last = next;
  }
  cout << ++cnt << endl;
  return 0;
}

