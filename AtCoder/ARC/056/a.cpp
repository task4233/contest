// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ARC 056 みんなでワイワイみかん a.cpp
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

//static const int MOD = 1000000007;

int main()
{
  int A, B, K, L;
  cin >> A >> B >> K >> L;
  ll tmp1 = K / L;
  ll tmp2 = K % L;
  ll ans = B * tmp1 + A * tmp2;
  ans = (ans > (B * tmp1 + B) ? (B * tmp1 + B) : ans);
  cout << ans << endl;
  return 0;
}

