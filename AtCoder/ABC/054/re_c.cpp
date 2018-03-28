// ------------------------------------
// Date:2018/ 3/24
// Problem:One Stroke Path re_c.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 8;


struct Edge {
  Edge(int _to)
    : to(_to){}
  int to;
};

vector< Edge > e[MAX_N];

int N;

bool check(vector< bool > state)
{
  REP(v, state.size()) {
    if (!state[v]) return false;
  }
  return true;
}

int dfs(int from)
{
  int res = 0;
  vector< bool > state(N, false);
  state[0] = true;
  
  queue< pair< int, vector< bool > > > q;
  q.push(make_pair(from, state));
  
  while(!q.empty()) {
    int from;
    vector< bool > _state;
    tie(from, _state) = q.front();
    q.pop();
    // debug(from);
    _state[from] = true;
    
    if (check(_state)) {
      res++;
    }
    EACH(to, e[from]) {
      if (_state[to.to]) continue;
      q.push(make_pair(to.to, _state));
    }
  }
  return res;
}

int main()
{
  int M;
  cin >> N >> M;
  vector< int > a(M);
  vector< int > b(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    e[a[i]].emplace_back(Edge(b[i]));
    e[b[i]].emplace_back(Edge(a[i]));
  }

  int ans = dfs(0);

  cout << ans << endl;

  
  return 0;
}

