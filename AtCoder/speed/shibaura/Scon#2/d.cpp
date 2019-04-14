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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

struct Edge {
  Edge(int _to, int _cost)
    : to(_to), cost(_cost) {}
  int to;
  int cost;
};

vector< Edge > e[MAX_N];
ll d[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  REP(i, N - 1) {
    CIN(a, b, c);
    a--; b--;
    e[a].emplace_back(Edge(b, c));
    e[b].emplace_back(Edge(a, c));
  }

  CIN(Q, K);

  fill_n(d, MAX_N, LINF);
  d[K - 1] = 0;
  queue< int > q;
  q.push(K - 1);
  while (!q.empty()) {
    int from = q.front(); q.pop();
    EACH(to, e[from]) {
      if (d[to.to] > d[from] + to.cost) {
	d[to.to] = d[from] + to.cost;
	q.push(to.to);
      }
    }
  }

  REP(qi, Q) {
    CIN(x, y);
    ll ans = d[x - 1] + d[y - 1];
    cout << ans << endl;
  }
  
  
  

  return 0;
}

