// ------------------------------------
// Date:2018/ 3/29
// Problem:_ _ _ b.cpp
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
const int MAX_N = 2e5 + 1;

int road[MAX_N];
int train[MAX_N];

map< pair< int, int >, int > cnt;

int N, K, L;

int root(int* par, int n)
{
  if (par[n] < 0) return n;
  return par[n] = root(par, par[n]);
}

bool unite(int* par, int p, int q)
{
  p = root(par, p);
  q = root(par, q);
  if (p == q) return false;
  if (par[p] > par[q]) swap(p, q);
  par[p] += par[q];
  par[q] = p;
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K >> L;
  fill_n(road, N, -1);
  fill_n(train, N, -1);

  vector< int > p(K);
  vector< int > q(K);
  
  REP(i, K) {
    cin >> p[i] >> q[i];
    p[i]--; q[i]--;
    unite(road, p[i], q[i]);
  }

  vector< int > r(L);
  vector< int > s(L);
  REP(i, L) {
    cin >> r[i] >> s[i];
    r[i]--; s[i]--;
    unite(train, r[i], s[i]);
  }

  REP(i, N)
    cnt[{root(road, i), root(train, i)}]++;

  REP(i, N)
    cout << cnt[{root(road, i), root(train, i)}] << (i < N - 1 ? " " : "\n");

  return 0;
}

