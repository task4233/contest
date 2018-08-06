#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "AC" : "WA") << endl;
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

  SCIN(S);
  bool ok = true;
  ok &= (S[0] == 'A');
  // OK(ok);
  int cnt = 0;
  FOR(i, 2, S.size() - 1) {
    if (S[i] == 'C') cnt++;
    else ok &= ((S[i] >= 'a' && S[i] <= 'z'));
  }
  // OK(ok);
  ok &= ('a' <= S[1] && S[1] <= 'z');
  ok &= ('a' <= S.back() && S.back() <= 'z');
  ok &= (cnt == 1);

  OK(ok);

  return 0;
}

