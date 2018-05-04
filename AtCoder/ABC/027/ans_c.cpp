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
const int MAX_N = 1e3 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N);

  ll rank = ((ll)floor(log2(N)) & 1);
  ll current = 1ll;
  
  REP(i, 60) {
    current <<= 1;
    if ((i + rank) % 2 == 0) {
      current++;
    }

    if (current > N) {
      cout << (i & 1 ? "Takahashi" : "Aoki") << endl;
      break;
    }
  }
  

  return 0;
}

