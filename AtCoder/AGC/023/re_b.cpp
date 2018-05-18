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
// O(N^3)くらいまでなら許す
const int MAX_N = 3e2 + 1;

int N;
string S[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) {
    cin >> S[i];
  }
    
  ll ans = 0ll;
  
  REP(i, N) {
    vector< string > tmp(N);
    REP(j, N) {
      tmp[j] = S[j].substr(i + 1) + S[j].substr(0, i + 1);
    }

    bool ok = true;
    REP(hi, N) {
      REP(wi, N) {
	if (tmp[hi][wi] != tmp[wi][hi]) {
	  ok = false;
	}
      }
    }
    if (ok) ans += N;
    // debug(ans);
  }

  cout << ans << endl;

  return 0;
}

