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

  SCIN(s);
  int A = s[0] - '0';
  vector< int > d(3);
  REP(i, 3) {
    d[i] = s[i + 1] - '0';
    // debug(d[i]);
  }
  REP(i, (1 << 3)) {
    // debug(i);
    int tmp = A;
    // debug(tmp);
    REP(j, 3) {
      if ((i >> j) & 1) {
        tmp += d[j];
      } else {
	tmp -= d[j];
      }
    }
    // debug(tmp);
    if (tmp == 7) {
      cout << A;
      REP(j, 3) {
	cout << ((i >> j) & 1 ? '+' : '-') << d[j];
      }
      cout << "=7"<< endl;
      return 0;
    }
  }

  return 0;
}

