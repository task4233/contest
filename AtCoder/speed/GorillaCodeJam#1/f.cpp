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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

string s;
// int memo[MAX_N][2];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;

  int zeroAns, oneAns;
  zeroAns = oneAns = 2;

  int zero, one;
  zero = one = -1;

  if (s[0] == '0') {
    zero = 1;
  } else {
    one = 1;
  }

  bool zeroFlag, oneFlag;
  zeroFlag = oneFlag = false;
  int ans = 2;
  FOR (i, 1, s.size() + 1) {
    // debug(i);
    // debug(one);
    // debug(zero);
    // debug(zeroAns);
    // debug(oneAns);
    if (i == s.size()) {
      // 最後の処理
      if (zeroFlag && oneFlag)
	ans = max(ans, one + zero);
      else if (zeroFlag)
	ans = max(ans, zero);
      else
	ans = max(ans, one);
      break;
      
    }

    if (s[i] == '0') {
      if (s[i - 1] == '1') {
	zeroAns = max(zeroAns, zero + one);
	zero = -1;
	zeroFlag = true;
      }
      if (zero < 0) {
	// ans = max(ans, one);
	// one = -1;
	zero = 1;
      } else {
	zero++;
      }
    } else {
      if (s[i - 1] == '0') {
	oneAns = max(oneAns, zero + one);
	one = -1;
	oneFlag = true;
      }
      if (one < 0) {
	// zero = -1;
	one = 1;
      } else {
	one++;
      }
    }
  }

  ans = max(max(ans, min(zeroAns, oneAns)), 2);

  cout << ans << endl;
  
  return 0;
}

