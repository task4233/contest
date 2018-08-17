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

bool cnt[26];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  SCIN(S);
  // map< char, int > mp;
  REP(i, S.size()) {
    cnt[S[i] - 97] = true;
  }

  string ans = "";
  if (S.size() < 26) {
    ans += S;
    REP(i, 26) {
      if (!cnt[i]) {
	ans += i + 97;
	cout << ans << endl;
	return 0;
      }
    }
  } else {
    int tmp = S.size() - 1;
    RREP(i, S.size() - 1) {
      if (S[i] < S[i + 1]) break;
      tmp = min(tmp, i);
    }

    if (tmp == 0) {
      cout << -1 << endl;
      return 0;
    }

    REP(i, S.size()) {
      if (i < tmp - 1) {
	ans += S[i];
	cnt[S[i] - 97] = false;
      } else {
	cnt[S[i] - 97] = true;
      }
    }

    FOR(i, S[tmp - 1] - 96, 26) {
      if (cnt[i]) {
	ans += i + 97;
	cout << ans << endl;
	return 0;
      }
    }
    
  }
  cout << -1 << endl;

  return 0;
}

