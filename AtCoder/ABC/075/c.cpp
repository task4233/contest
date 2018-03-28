// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 075 Bridge c.cpp
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

//static const int MOD = 1000000007;
static const int MAX_N = 55;

int par[MAX_N];

void init(int n)
{
  REP(i, n) {
    par[i] = -1;
  }
}

int root(int x)
{
  if (par[x] < 0) return x;
  return par[x] = root(par[x]);
}

bool unite(int x, int y)
{
  x = root(x);
  y = root(y);
  // 閉路ができちゃってる時
  if (x == y) return false;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
  return true;
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  vector< int > a(M);
  vector< int > b(M);
  // 全ての辺に対して全探索で、Union-Find木であっさり？


  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }


  int cnt = 0;
  REP(i, M) {
    init(N);
    REP(j, M) {
      if (i == j) continue;
      unite(a[j], b[j]);
    }
    map< int, int > m;
    REP(j, N) {
      m[root(j)]++;
    }
    if (m.size() != 1) {
      cnt++;
    }
  }

  cout << cnt << endl;
  return 0;
}

