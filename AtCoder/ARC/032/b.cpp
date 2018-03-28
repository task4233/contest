// ------------------------------------
// Date:2018/ 3/10
// Problem:ARC 032 道路工事 b.cpp
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
static const int MAX_N = 101010;

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
  else return par[n] = root(par[n]);
}

bool unite(int a, int b)
{
  a = root(a);
  b = root(b);
  // すでに繋がってる
  if (a == b) return false;
  if (par[a] > par[b]) swap(a, b);
  par[a] += par[b];
  par[b] = a;
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  init(N);

  REP(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    unite(a, b);
  }

  map< int, int > m;
  REP(i, N) {
    m[root(i)]++;
  }

  int ans = m.size() - 1;
  cout << ans << endl;
  
  return 0;
}

