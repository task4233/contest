// ------------------------------------
// Date:2018/ 4/ 3
// Problem:hight score _ d.cpp
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
const int MAX_N = 1e5 + 10;

int N, M;

ll score[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< ll > l(N);
  vector< ll > r(N);
  vector< ll > s(N);

  ll sum = 0ll;
  REP(i, N) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--; r[i]--;
    score[l[i]] += s[i];
    score[r[i] + 1] -= s[i];
    sum += s[i];
  }

  REP(i, MAX_N)
    if (i > 0) score[i] += score[i - 1];

  ll mn = INF;
  REP(i, M) {
    mn = min(mn, score[i]);
    // debug(score[i]);
  }

  ll ans = sum - mn;
  cout << ans << endl;
  
  return 0;
}

