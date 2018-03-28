// ------------------------------------
// Date:2018/ 3/20
// Problem:A- ファイティング・タカハシ . re_a.cpp
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
  LCIN(N);
  SCIN(s);
  ll num, cnt, ans;
  num = cnt = ans = 0;
  // 全部Aだった時にその値を出力
  if (s == string(s.size(), 'A')) {
    ans = (1 + s.size() * N) * s.size() * N / 2;
    // OK(true);
    cout << ans << endl;
    return 0;
  }
  
  // 最初のAを先にansに加えておく
  for(num; num < s.size(); ++num) {
    if (s[num] == 'B') break;
    cnt++;
    ans += cnt;
    // debug(ans);
  }
  // debug(ans);
  
  // 最後のAを先にansに加えておく
  cnt = 0;
  RFOR(i, num, s.size()) {
    if (s[i] == 'B') cnt = 0;
    else {
      cnt++;
      ans += cnt;
    }
    // debug(ans);
  }
  
  // 途中のAをカウントしてN-1倍する
  ll tmp = 0;
  rotate(s.begin(), s.begin() + num, s.end());
  REP(i, s.size()) {
    if (s[i] == 'B') cnt = 0;
    else {
      cnt++;
      tmp += cnt;
    }
  }
  ans += tmp * (N - 1);

  cout << ans << endl;

  return 0;
}

