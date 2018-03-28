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

static const int MAX_N = 101;

int N, M;
int par[MAX_N];

void init(int _n)
{
  REP(i, _n) {
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

vector< int > getMember(int r)
{
  vector< int > res;
  REP(i, N) {
    if (root(r) == root(i)) {
      res.emplace_back(i + 1);
    }
  }
  return res;
}

int main()
{

  cin >> N >> M;
  init(N);

  REP(i, M) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    unite(u, v);
  }

  set< int > item;
  REP(i, N) {
    item.erase(root(i));
    item.insert(root(i));
    // debug(root(i));
  }


  cout << endl << "Select root number." << endl;
  EACH(i, item) cout << i << " ";
  cout << endl;
  printf("> ");

  int inputNum;
  cin >> inputNum;
  
  vector< int > ans;
  ans = getMember(inputNum);

  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }
  
  return 0;
}

