// ------------------------------------
// Date:2018/ 4/ 2
// Problem:C - 壁抜け rere_c.cpp
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
const int MAX_N = 10;

/*
struct Pos {
  Pos(int _y, int _x)
    : y(_y), x(_x){}
  int x;
  int y;
  };*/

typedef pair< int, int > Pos;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

typedef pair< int, Pos > D;

int H, W, T;
string s[MAX_N];
int d[MAX_N][MAX_N];

Pos S, G;

bool dijkstra(int time)
{
  REP(hi, H) fill_n(d[hi], W, INF);
  d[S.first][S.second] = 0;

  // D := pair< cost(int), Pos(y(int), x(int)) > 
  priority_queue< Pos > q;
  q.push(S);

  while(!q.empty()) {
    Pos from = q.top(); q.pop();
    // Gに辿りつけたらtrue
    if (from == G) return true;
    REP(i, 4) {
      Pos next;
      next.second = from.second + dx[i];
      next.first = from.first + dy[i];
      int cost = d[from.first][from.second];
      // 範囲外にでちゃう時はスルー
      if (!(0 <= next.second && next.second < W &&
      	    0 <= next.first && next.first < H)) continue;
      // 重みを設定
      int bias = (s[next.first][next.second] == '#' ? time : 1);
      // 今の経路よりも短い経路がある時はスルー
      if (d[next.first][next.second] <= cost + bias) continue;
      // 制限時間を超えてもスルー
      if (cost + bias > T) continue;
      d[next.first][next.second] = cost + bias;
      q.push(next);
    }
  }

  // Gに辿りつけなかった時はfalse
  return false;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> T;
  REP(hi, H) {
    cin >> s[hi];
    REP(wi, W) {
      if (s[hi][wi] == 'S') S = make_pair(hi, wi);
      if (s[hi][wi] == 'G') G = make_pair(hi, wi);
    }
  }

  ll lb = 0;
  ll ub = T;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (dijkstra(mid)) lb = mid;
    else ub = mid;
  }

  ll ans = lb;

  cout << ans << endl;
  

  return 0;
}

