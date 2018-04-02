// ------------------------------------
// Date:2018/ 3/31
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int cnt[26];

int main()
{

  bool check = false;
  memset(cnt, 0, sizeof(cnt));
  string s;
  cin >> s;

  int last = INF;
  // state: 0:increse / 1:decrease
  int state = -1;
  cnt[s[0] - 97]++;
  FOR(i, 1, s.size()) {
    cnt[s[i] - 97]++;
    if (s[i] > s[i - 1]) {
      if (state != 0) {
	state = 0;
	last = i;
      }
    } else {
      if (state != 1) {
	state = 1;
	last = i;
      }
    }
  }
  
  REP(i, 26) {
    if (cnt[i] == 0) {
      // 使ってないもじが会った時
      cout << s;
      printf("%c\n", i + 97);
      return 0;
    }
    if (i == 25) {
      if (s == "zyxwvutsrqponmlkjihgfedcba") {
	// 下がりっぱなしのとき
	cout << -1 << endl;
	return 0;
      }
      if (state == 0) {
	// 結局上がってたとき
	// increase
	// OK(true);
	REP(i, last - 1) {
	  cout << s[i];
	  cnt[s[i] - 97]--;
	}
	REP(i, 26) {
	  if (cnt[i] == 1 && s[last - 1] < i + 97) {
	    printf("%c\n", i + 97);
	    return 0;
	  }
	}
      } else {
	// 結局下がってた時
	// decrease
	// OK(false);
	REP(i, last - 2) {
	  cout << s[i];
	  cnt[s[i] - 97]--; 
	}
	// cout << endl;
	REP(i, 26) {
	  if (cnt[i] == 1 && s[last - 2] < i + 97) {
	    printf("%c\n", i + 97);
	    return 0;
	  }
	}
      }
    }
  }
  

  return 0;
}

