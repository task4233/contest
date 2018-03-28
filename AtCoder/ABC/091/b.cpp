// ------------------------------------
// Date:2018/ 3/17
// Problem:_ _ _ b.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

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
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< string > s(N);
  REP(i, N) {
    cin >> s[i];
  }
  CIN(M);
  vector< string > t(M);
  REP(i, M) {
    cin >>t[i];
  }

  sort(ALL(s));
  sort(ALL(t));

  string str = "";
  int cnt;
  int ans = 0;
  REP(i, N) {
    cnt = 0;
    str = s[i];
    REP(j, N) {
      if (str == s[j]) {
      cnt++;
      }
    }
    REP(j, M) {
      if (str == t[j]) {
	cnt--;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  
  return 0;
}

