// ------------------------------------
// Date:2018/ 2/23
// Problem:ABC 048 BoxesAndCandies c.cpp
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

using ll = long long;

#define MOD 1000000007

int N;
int x;

int main()
{
  ll cnt = 0ll;
  cin >> N >> x;
  vector<int> a(N);
  REP(i,N) {
    cin >> a[i];
  }
  
  REP(i,N-1) {
    if (a[i] + a[i+1] > x) {
      if (a[i] > x) {
        cnt += a[i+1];
        a[i+1] = 0;
        cnt += a[i] - x;
        a[i] = x;
      } else {
        cnt += a[i+1] - (x-a[i]);
        a[i+1] = x - a[i];
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

