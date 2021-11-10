// ------------------------------------
// Date:2018/ 3/21
// Problem:Extra GreatestCommon Divisor Extgcd.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

int extgcd(int a, int b, int& x, int& y)
{
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    debug(d);
    y -= (a / b) * x;
      cout << "-----------------------------" << endl;
  debug(a);
  debug(b);
  debug(x);
  debug(y);
  cout << "-----------------------------" << endl;
  } else {
    x = 1; y = 0;
  }
  /*
  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
  debug(a);
  debug(b);
  debug(x);
  debug(y);
  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
  */
  return d;
}

int main()
{
  CIN(a, b);
  int x, y;
  cout << extgcd(a, b, x, y) << endl;
  printf("x = %d\ny = %d\n", x, y);
  return 0;
}

