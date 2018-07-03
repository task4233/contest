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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;

  bool flag = false;
  ll ans = 0ll;
  ll tmp = 0ll;
  REP(i, s.size()) {
    tmp += s[i] - '0';
  }
  if (s[0] == '9') {
    ans += 9;
  } else {
    ans += s[0] - '0';
    ans--;
    flag = true;
  }
  FOR(i, 1, s.size()) {
    if (flag) {
      ans += 9;
      continue;
    }
    if (s[i] == '9') {
      ans += 9;
    } else {
      ans += 9;
      ans--;
      flag = true;
    }
  }

  ans = max(ans, tmp);

  cout << ans << endl;

  return 0;
}

