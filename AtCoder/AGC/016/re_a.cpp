// ------------------------------------
// Date:2018/ 3/20
// Problem:A - Shrinking re_a.cpp
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

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int main()
{
  SCIN(s);
  int ans = INF;
  REP(i, 26) {
    // OK(true);
    char ch = i + 97;
    string tmp = s;
    int cnt = 0;
    bool ok = false;
    REP(i, s.size()) {
      if (s[i] != ch) break;
      if (i == s.size() - 1) ok = true;
    }
    while(!ok) {
      // OK(false);
      REP(j, tmp.size() - 1) {
	if (tmp[j] == ch or tmp[j + 1] == ch) {
	  tmp[j] = ch;
	}
      }
      tmp.pop_back();
      REP(j, tmp.size()) {
	if (tmp[j] != ch) break;
	if (j == tmp.size() - 1) ok = true;
      }
      if (tmp.size() == 0) ok = true;
      cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}

