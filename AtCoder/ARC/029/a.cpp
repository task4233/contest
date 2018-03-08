// ------------------------------------
// Date:2018/ 2/27
// Problem:ARC 029 高橋君とお肉 a.cpp
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
  int N;
  cin >> N;
  vector< int > t(N);
  REP(i, N) {
    cin >> t[i];
  }
  sort(ALL(t));
  int cnt1, cnt2;
  cnt1 = t[N - 1];
  cnt2 = t[N - 2];
  RREP(i, N - 2) {
    if (cnt1 < cnt2) {
      cnt1 += t[i];
    } else {
      cnt2 += t[i];
    }
  }
  
  cout << max(cnt1, cnt2) << endl;
  return 0;
}

