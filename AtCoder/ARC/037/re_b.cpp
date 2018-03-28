// ------------------------------------
// Date:2018/ 3/10
// Problem:ARC 037 バウムテスト re_b.cpp
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
static const int MAX_N = 101;

int par[MAX_N];

void init(int N)
{
  REP(i, N) {
    par[i] = -1;
  }
}

int root(int n)
{
  if (par[n] < 0) return n;
  return par[n] = root(par[n]);
}

bool unite(int u, int v)
{
  u = root(u);
  v = root(v);
  if (u == v) return false;
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  init(N);

  map< int, int > ans;
  REP(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    if (!unite(u, v)) ans[root(u)] = -1;
  }

  REP(i, N) {
    if (ans[root(i)] > -1) ans[root(i)]++;
  }

  int cnt = 0;
  REP(i, N) {
    if (ans[i] > 0) cnt++;
  }
  cout << cnt << endl;
  
  return 0;
}

