// ------------------------------------
// Date:2018/ 3/12
// Problem:ABC 073 Theater b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;
const int MAX_N = 100010;

int state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(state, false, sizeof(state));
  int N;
  cin >> N;

  REP(i, N) {
    int l, r;
    cin >> l >> r;
    l--;
    state[l]++;
    state[r]--;
  }

  REP(i, MAX_N - 1) {
    state[i + 1] += state[i];
  }
  int ans = 0;
  REP(i, MAX_N) {
    if (state[i] > 0) ans++;
  }

  cout << ans << endl;
  
  return 0;
}

