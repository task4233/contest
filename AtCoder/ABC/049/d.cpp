// ------------------------------------
// Date:2018/ 3/10
// Problem:ABC 049 Connectivity d.cpp
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
static const int MAX_N = 201010;

// par[0]: road / par[1]: train
int par[2][MAX_N];



int root(int n, int type)
{
  if (par[type][n] < 0) {
    return n;
  } else {
    return par[type][n] = root(par[type][n], type);
  }
}

bool unite(int p, int q, int type)
{
  p = root(p, type);
  q = root(q, type);
  if (p == q) return false;
  if (par[type][p] > par[type][q]) swap(p, q);
  par[type][p] += par[type][q];
  par[type][q] = p;
  return true;
}

bool same(int p, int q, int type)
{
  return root(p, type) == root(q, type);
}


void init(int n)
{
  REP(i, n) {
    par[0][i] = -1;
    par[1][i] = -1;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  map< pair< int, int>, int> m;
  int N, K, L;
  cin >> N >> K >> L;
  init(N);
  // road
  REP(i, K) {
    int p, q;
    cin >> p >> q;
    --p;
    --q;
    unite(p, q, 0);
  }

  // train
  REP(i, L) {
    int r, s;
    cin >> r >> s;
    --r;
    --s;
    unite(r, s, 1);
  }

  REP(i, N) {
    m[make_pair(root(i, 0), root(i, 1))]++;
  }

  REP(i, N) {
    cout << m[make_pair(root(i, 0), root(i, 1))];
    if (i != N-1) cout << " ";
    else cout << endl;
  }
  /*
  int cnt;
  bool ok;
  REP(i, N) {
    cnt = 0;
    REP(j, N) {
      ok = true;
      REP(type, 2) {
	// printf("root(%d):%d / root(%d):%d\n", i, root(i, type), j, root(j, type));
	if (not( same( root(i, type), root(j, type), type ) )) ok = false;
      }
      if (ok) cnt++;
    }

    cout << cnt;
    if (i != N-1) cout << " ";
    else cout << endl;
  }
  */
  return 0;
}


//1 1 2 1 2 2 2
