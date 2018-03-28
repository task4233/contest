// ------------------------------------
// Date:2018/ 3/27
// Problem:C - 収集王 c.cpp
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
const int MAX_N = 1e5 + 1;

ll R, C, K, N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> R >> C >> K >> N;

  vector< int > r(N);
  vector< int > l(N);
  vector< int > rowCnt(MAX_N, 0);
  vector< int > lineCnt(MAX_N, 0);
  
  REP(i, N) {
    cin >> r[i] >> l[i];
    r[i]--; l[i]--;
    rowCnt[r[i]]++;
    lineCnt[l[i]]++;
  }

  vector< int > line(MAX_N, 0);

  REP(i, C)
    line[lineCnt[i]]++;
  
  ll ans = 0ll;
  REP(i, R) {
    if (K - rowCnt[i] < 0) continue;
    ans += line[K - rowCnt[i]]; 
  }

  
  REP(i, N) {
    if (rowCnt[r[i]] + lineCnt[l[i]] == K + 1) ans++;
    if (rowCnt[r[i]] + lineCnt[l[i]] == K) ans--;
  }
  
  cout << ans << endl;
  
  return 0;
}

