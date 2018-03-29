// ------------------------------------
// Date:2018/ 3/29
// Problem:手芸王 / / b.cpp
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  SCIN(S);

  bool ok = false;
  string tmp = "b";
  if (S == tmp) {
    cout << 0 << endl;
    return 0;
  }
  int cnt = 1;
  while(cnt * 2 - 1 <= S.size()) {
    switch((cnt - 1) % 3) {
    case 0:
      tmp = "a" + tmp + "c";
      break;
    case 1:
      tmp = "c" + tmp + "a";
      break;
    case 2:
      tmp = "b" + tmp + "b";
      break;
    }
    if (tmp == S) {
      ok = true;
      break;
    }
    cnt++;
    // debug(cnt);
    // debug(tmp);
  }

  if (!ok) cnt = -1;
  cout << cnt << endl;

  return 0;
}

