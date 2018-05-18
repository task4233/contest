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
const int MAX_N = 8;

int N, M;
int a[MAX_N * MAX_N], b[MAX_N * MAX_N];

typedef pair< int, vector< bool > > PIV;

vector< int > e[MAX_N];

int solve()
{
  int res = 0;
  
  vector< bool > state(N, false);
  queue< PIV > q;
  q.push(make_pair(0, state));

  while(!q.empty()) {
    PIV from = q.front(); q.pop();
    from.second[from.first] = true;

    bool ok = true;
    EACH(i, from.second) {
      if (!i) ok = false;
    }
    if (ok) res++;
    
    EACH(ni, e[from.first]) {
      if (from.second[ni]) continue;
      q.push(make_pair(ni, from.second));
    }
  }

  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, M) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    e[a[i]].emplace_back(b[i]);
    e[b[i]].emplace_back(a[i]);
  }

  int ans = solve();

  cout << ans << endl;

  return 0;
}

