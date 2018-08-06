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

ll n, m, s, t;

struct Edge {
  Edge(int _to, ll _yen, ll _snuke)
    :to(_to), yen(_yen), snuke(_snuke){}
  int to;
  ll yen;
  ll snuke;
};

vector< Edge > e[MAX_N];
ll yD[MAX_N];
ll sD[MAX_N];

typedef pair< ll, int > P;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m >> s >> t;
  s--; t--;
  REP(i, m) {
    LCIN(u, v, a, b);
    u--; v--;
    e[u].emplace_back(Edge(v, a, b));
    e[v].emplace_back(Edge(u, a, b));
  }

  priority_queue< P, vector< P >, greater< P > > q;
  fill_n(yD, MAX_N, LINF);
  // vector< bool > state(m, false);
  yD[s] = 0;
  // state[s] = true;
  q.push(P(0, s));

  while (!q.empty()) {
    ll dist; int from;
    tie(dist, from) = q.top(); q.pop();
    if (yD[from] < dist) continue;
    EACH(to, e[from]) {
      if (yD[to.to] > yD[from] + to.yen) {
	yD[to.to] = yD[from] + to.yen;
	q.push(P(yD[to.to], to.to));
      }
    }
  }

  q = decltype(q)();
  fill_n(sD, MAX_N, LINF);
  sD[t] = 0;
  q.push(P(0, t));

  while (!q.empty()) {
    ll dist; int from;
    tie(dist, from) = q.top(); q.pop();
    if (sD[from] < dist) continue;
    EACH(to, e[from]) {
      if (sD[to.to] > sD[from] + to.snuke) {
	sD[to.to] = sD[from] + to.snuke;
	q.push(P(sD[to.to], to.to));
      }
    }
  }
  
  vector< ll > ans(n + 1);
  RREP(i, n) {
    // debug(i);
    // debug(sD[i]);
    // debug(yD[i]);
    ll tmp = 1e15 - (sD[i] + yD[i]);
    ans[i] = max(ans[i + 1], tmp);
  }

  REP(i, n) {
    cout << ans[i] << endl;
  }

  return 0;
}

