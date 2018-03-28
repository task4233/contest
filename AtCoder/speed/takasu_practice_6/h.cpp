// ------------------------------------
// Date:2018/ 3/26
// Problem:B - 駐車場 h.cpp
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
const int MAX_N = 2e5 + 1;

int N, M, S;

int par[MAX_N];
vector< int > e[MAX_N];

void init()
{
  REP(i, N) {
    par[i] = -1;
  }
}

int root(int a)
{
  if (par[a] < 0) return a;
  return par[a] = root(par[a]);
}

bool unite(int a, int b)
{
  a = root(a);
  b = root(b);
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
  
  cin >> N >> M >> S;
  vector< int > u(M);
  vector< int > v(M);
  REP(i, M) {
    CIN(_u, _v);
    u[i] = _u - 1;
    v[i] = _v - 1;
    e[u[i]].emplace_back(v[i]);
    e[v[i]].emplace_back(u[i]);
  }


  vector< int > ans;
  
  init();
  RREP(i, N) {
    EACH(j, e[i]) {
      if (j > i) {
	unite(i, j);
      }
    }
    if (root(i) == root(S - 1)) {
    ans.emplace_back(i + 1);
    }  
  }
  
  RREP(i, ans.size()) {
    cout << ans[i] << endl;
  }

  return 0;
}

