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

  CIN(N, x);

  if (x == 1 || x == 2 * N - 1) {
    OK(false);
  } else {
    OK(true);
    deque< int > ans;
    ans.push_back(x - 1);
    ans.push_back(x);
    ans.push_back(x + 1);

    int cnt = 0;
    FOR(i, 1, 2 * N) {
      if (x - 1 <= i && i <= x + 1) {
	continue;
      }
      if (cnt < N - 2) {
	cnt++;
	ans.push_front(i);
      } else {
	ans.push_back(i);
      }
    }
    EACH(ai, ans) {
      cout << ai << endl;
    }
  }
  

  return 0;
}

