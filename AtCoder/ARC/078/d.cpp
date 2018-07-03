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
const int MAX_N = 1e5 + 1;

int N;
int dFenec[MAX_N];
int dSnuke[MAX_N];
vector< int > e[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N - 1) {
    CIN(a, b);
    a--; b--;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }

  fill_n(dFenec, N, INF);
  fill_n(dSnuke, N, INF);

  {
    // Fenec
    queue< int > q;
    q.push(0);
    dFenec[0] = 0;
    while(!q.empty()) {
      int from = q.front(); q.pop();
      EACH(to, e[from]) {
	// OK(true);
	if (dFenec[to] == INF) {
	  // OK(true);
	  dFenec[to] = dFenec[from] + 1;
	  q.push(to);
	}
      }
    }
  }
  
  {
    // Snuke
    queue< int > q;
    q.push(N - 1);
    dSnuke[N - 1] = 0;
    while(!q.empty()) {
      int from = q.front(); q.pop();
      EACH(to, e[from]) {
	// OK(true);
	if (dSnuke[to] == INF) {
	  dSnuke[to] = dSnuke[from] + 1;
	  q.push(to);
	}
      }
    }
  }
  /*
  REP(i, N) {
    debug(dFenec[i]);
  }
  REP(i, N) {
    debug(dSnuke[i]);
  }
  */

  int res = 0;
  REP(i, N) {
    if (dFenec[i] <= dSnuke[i]) res++;
    else                        res--;
  }

  cout << (res > 0 ? "Fennec" : "Snuke") << endl; 
  
  return 0;
}

