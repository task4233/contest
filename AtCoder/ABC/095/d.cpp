// ------------------------------------
// Date:2018/ 4/21
// Problem:/ / / d.cpp
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

int N;
ll C;
ll memo[MAX_N];
int state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  // x, value
  vector< pair< ll, ll > > x(N);

  ll ans = 0ll;
  REP(i, N) {
    LCIN(a, b);
    x[i] = make_pair(a, b);
    ans += x[i].second;
  }
  
  memo[0] = 0;
  REP(i, N) {
    memo[i + 1] = memo[i] + x[i].second;
  }

  REP(i, N) {
    if (abs(x[(i + 1) % N].first - x[i].first) > v[i]) state[i]++;
  }

  int tmp = 0;
  REP(i, N) {
    if (state[i] > 1) ans -= x[i].second;
  }

  ll dist = 0ll;
  // 正の方向
  REP(i, )


  // 負の方向
  queue< pair< int, int > > q;
  q.push(0);

  ll plusAns = 0;
  while(!q.empty()) {
    int from = q.first(); q.pop();
    FOR(i, from) {
      ll dist = x[from + 1].second - (min(x[to].first - x[from],first, C + x[from].first - x[to].first));
      if (dist < 0) continue;
      plusAns += dist;
      q.push(i);
    }
  }


  return 0;
}
