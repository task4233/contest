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
const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N, M;

struct Edge {
  Edge(int _from, int _to, ll _cost)
    : from(_from), to(_to), cost(_cost) {}
  int from;
  int to;
  ll cost;
};

vector< Edge > e;
ll d[MAX_N];
// bool state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fill_n(d, MAX_N, LINF);

  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  vector< ll > c(M);
  REP(i, M) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    e.emplace_back(Edge(a[i], b[i], -1ll * c[i]));
  }

  d[0] = 0ll;
  // state[0] = true;
  
  REP(i, N) {
    
    EACH(ei, e) {
      // if (!state[ei.from]) continue;
      if (d[ei.from] != LINF && d[ei.to] > d[ei.from] + ei.cost) {
	d[ei.to] = d[ei.from] + ei.cost;
	// state[ei.to] = true;
	
	if (i == N - 1) {// && ei.to == N - 1) {
	  cout << "inf" << endl;
	  return 0;
	}
      }
    }
  }

  
  ll ans = -1ll * d[N - 1];
  cout << ans << endl;

  
  REP(i, N) {
    debug(d[i]);
  }
  
  
  return 0;
}

