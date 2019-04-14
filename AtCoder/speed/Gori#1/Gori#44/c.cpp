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
  vector< int > C(N);
  vector< int > S(N);
  vector< int > F(N);
  REP(i, N - 1) {
    cin >> C[i] >> S[i] >> F[i];
  }

  int tm;
  REP(i, N - 1) {
    tm = 0;
    FOR(j, i, N - 1) {
      if (tm < S[j]) {
	tm = S[j];
      } else {
	if (tm % F[j] != 0) {
	  tm += F[j] - tm % F[j];
	}
      }
      tm += C[j];
    }
    cout << tm << endl;
  }

  cout << 0 << endl;

  return 0;
}

