// ------------------------------------
// Date:2018/ 3/24
// Problem:収穫王 / / c.cpp
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
static const int MAX_N = 1e5 + 1;

int line[MAX_N];
int row[MAX_N];

int main()
{
  CIN(R, C, K, N);
  vector< int > l(N);
  vector< int > r(N);
  memset(row, 0, sizeof(row));
  memset(line, 0, sizeof(line));
  REP(i, N) {
    cin >> r[i] >> r[i];
    r[i]--;
    l[i]--;
    line[l[i]]++;
    row[r[i]]++;
  }

  sort(line, line + MAX_N);
  sort(row, row + MAX_N);
  
  int ans = 0;
  REP(ri, R) {
    int tmp = K - row[ri];
    debug(tmp);
    ans += upper_bound(line, line + MAX_N, tmp) - upper_bound(line, line + MAX_N, tmp + 1);
  }

  cout << ans << endl;
  return 0;
}

