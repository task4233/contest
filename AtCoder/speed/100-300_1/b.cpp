// ------------------------------------
// Date:2018/ 3/13
// Problem:one stroke path b.cpp
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

int N, M;
bool l[MAX_N][MAX_N] = {false};
int V[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    l[a[i]][b[i]] = l[b[i]][a[i]] = true;
  }

  REP(i, N) {
    V[i] = i;
  }

  bool ok;
  int ans = 0;
  do {
    ok = true;
    if (V[0] != 0) continue;
    REP(i, N - 1) {
      if (!l[V[i]][V[i + 1]]) {
	ok = false;
      }
    }
    if (ok) ans++;
  } while(next_permutation(V, V + N));

  cout << ans << endl;
  
  return 0;
}

