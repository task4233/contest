// ------------------------------------
// Date:2018/ 3/17
// Problem:C- Blue Bird d.cpp
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

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
static const int INF = 1000000001;
static const int MAX_N = 301;

int N, M;
bool state[MAX_N] = {false};
int dist[MAX_N][MAX_N] = {-1};
int memo[MAX_N][MAX_N] = {0};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, M) {
    CIN(u, v, l);
    dist[u - 1][v - 1] = l;
    dist[v - 1][u - 1] = l;
  }

  queue< int > q;
  q.push(0);
  while(!q.empty()) {
    int from = q.front();
    q.pop();
    if (from == 0) break;
    REP(to, N) {
      if (dist[from][to] == -1) continue;
      if (state[to]) break;
      int 
    }
  }

  cout << ans << endl;

  return 0;
}

