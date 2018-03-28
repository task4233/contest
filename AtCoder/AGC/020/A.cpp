// ------------------------------------
// Date:2018/ 3/19
// Problem:- Move and A.cpp
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
#define debug(x) cerr << #x << ":" << x << "\n";
#define OK(ok) cout << (ok ? "Yes" : "No") <<　"\n";
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
  string ans = "";
  CIN(N, A, B);
  REP(i, 575) {
    if (not(i & 1)) {
      // Alice
      if (A > B) {
	if (A - 1 == B or A - 1 < 1) ans = "Borys";
	else A--;
      } else {
	if (A + 1 == B or A + 1 > N) ans = "Borys";
	else A++;
      }
    } else {
      // Borys
      if (B > A) {
	if (B - 1 == A or B - 1 < 1) ans = "Alice";
	else B--;
      } else {
	if (B + 1 == A or B + 1 > N) ans = "Alice";
	else B++;
      }
    }
    if (ans != "") break;
  }

  cout << ans << endl;
  return 0;
}

