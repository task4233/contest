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

ll I, O, T, J, L, S, Z;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll ans1 = 0ll;
  ll ans2 = 0ll;
  cin >> I >> O >> T >> J >> L >> S >> Z;

  {
    ans1 += I / 2 * 2;
    ans1 += J / 2 * 2;
    ans1 += L / 2 * 2;
    ans1 += O;
  }

  if (I > 0 && J > 0 && L > 0) {
    ans2 += 3;
    I--; J--; L--;
    ans2 += I / 2 * 2;
    ans2 += J / 2 * 2;
    ans2 += L / 2 * 2;
    ans2 += O;
  }
  
  {
    // debug(ans1);
    // debug(ans2);
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}

