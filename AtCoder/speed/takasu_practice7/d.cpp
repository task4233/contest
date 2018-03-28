// ------------------------------------
// Date:2018/ 3/17
// Problem:One storoke path d.cpp
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
static const int MAX_N = 8;

int p[MAX_N];
bool l[MAX_N][MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  memset(l, false, sizeof(l));
  int N, M;
  cin >> N >> M;

  
  REP(i, N) {
    p[i] = i;
  }
  vector< int > a(M);
  vector< int > b(M);
  //cout << "ok" << endl;
  REP(i, M) {
    int ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    l[ai][bi] = l[bi][ai] = true;
  }

  bool ok;
  ll ans = 0ll;
  do {
    ok = true;
    if (p[0] != 0) continue;
    REP(i, N - 1) {
      if (!l[p[i]][p[i + 1]]) ok = false;
    }
    if (ok) ans++;
  } while (next_permutation(p, p + N));

  cout << ans << endl;
    
  return 0;
}

