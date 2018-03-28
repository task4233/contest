// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ a.cpp
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

int main()
{
  CIN(N);
  vector< int > a;
  if (N >= 8) {
    a.push_back(8);
    N -= 8;
  }
  if (N >= 4) {
    a.push_back(4);
    N -= 4;
  }
  if (N >= 2) {
    a.push_back(2);
    N -= 2;
  }
  if (N >= 1) {
    a.push_back(1);
  }

  cout << a.size() << endl;
  REP(i, a.size()) {
    cout << a[i] << endl;
  }
  

  return 0;
}

