// ------------------------------------
// Date:2018/ 3/17
// Problem:_ _ _ c.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 101;
typedef pair< int, int > PI;

int N;
vector< PI > r;
vector< PI > b;

// memo[今見ている点][残りの頂点数]
int memo[MAX_N][MAX_N];

int solve(int bsize, int rsize)
{
  vector< PI > tmp;
  int cnt = 0;
  int res = 0;
  bool ok = true;
  REP(bi, bsize) {
    REP(ri, rsize) {
      if (r[ri].first < b[bi].first and r[ri].second < b[bi].second) {
	cnt++;
	tmp.emplace_back(make_pair(ri, bi));
      }
    }
    if (cnt == 1) {
      res++;
      debug(r[tmp[0].first].first);
      debug(r[tmp[0].first].second);
      debug(b[tmp[0].second].first);
      debug(b[tmp[0].second].second);
      r[tmp[0].first] = r.back();
      r.pop_back();
      b[tmp[0].second] = b.back();
      b.pop_back();
    } else if (cnt == 0) {
      return 0;
    } else {
      int ret = 0;
      REP(j, cnt) {
	debug(r[tmp[0].first].first);
	debug(r[tmp[0].first].second);
	debug(b[tmp[0].second].first);
	debug(b[tmp[0].second].second);
	r[tmp[0].first] = r.back();
	r.pop_back();
	b[tmp[0].second] = b.back();
	b.pop_back();	
	ret = max(ret, solve(b.size(), r.size()));
      }
      ok = false;
    }
  }
  cout << "ok" << endl;
  if (!ok) return solve(b.size(), r.size()) + res;
  else return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(memo, 0, sizeof(memo));
  cin >> N;
  r.resize(N);
  REP(i, N) {
    CIN(x, y);
    r[i] = make_pair(x, y);
  }
  b.resize(N);
  REP(i, N) {
    CIN(x, y);
    b[i] = make_pair(x, y);
  }

  sort(ALL(r), [](PI x, PI y) {
      return min(x.first, x.second) < min(y.first, y.second);
  });
  sort(ALL(b), [](PI x, PI y) {
      return min(x.first, x.second) < min(y.first, y.second);
  });

  int ans = solve(b.size(), r.size());


  cout << ans << endl;

  return 0;
}

