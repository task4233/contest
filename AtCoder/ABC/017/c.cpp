// ------------------------------------
// Date:2018/ 4/ 2
// Problem:C - ハイスコア c.cpp
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

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e7 + 1;

int N, M;

ll table[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< int > l(N);
  vector< int > r(N);
  vector< int > s(N);

  fill_n(table, MAX_N, 0ll);

  ll ans = 0ll;
  REP(i, N) {
    cin >> l[i] >> r[i] >> s[i];
    table[l[i]] += s[i];
    table[r[i] + 1] -= s[i];
    ans += s[i];
  }

  ll mn = INF;
  FOR(i, 1, M + 1) {
    table[i] += table[i - 1];
    mn = min(mn, table[i]); 
    // if (i > 1) table[i - 2] = table[i - 2] < 0 ? 0 : table[i - 2];
  }
  
  ans -= mn;
  cout << ans << endl;
  
  return 0;
}

