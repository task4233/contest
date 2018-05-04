#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "YES" : "NO") << endl;
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

int sx, sy, gx, gy;
int T, V, N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> sx >> sy >> gx >> gy; 
  cin >> T >> V >> N;

  bool ok = false;
  REP(i, N) {
    CIN(x, y);
    int fdist = (sx - x) * (sx - x) + (sy - y) * (sy - y);
    int gdist = (gx - x) * (gx - x) + (gy - y) * (gy - y);
    double dist = sqrt((double)fdist) + sqrt((double)gdist);
    // debug(dist);
    if (dist <= T * V) ok = true; 
  }

  OK(ok);
    
  return 0;
}

