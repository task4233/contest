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
const int MAX_N = 5e2 + 5;

int H, W, K;
string S[MAX_N];
bool state[MAX_N][MAX_N];

void init(int hi, int wi)
{
  state[hi][wi] = true;
  FOR(hj, -K + 1, K) {
    int tmp = K - abs(hj);
    FOR(wj, -tmp + 1, tmp){
      if (!(0 <= hi + hj && hi + hj < H and
	    0 <= wi + wj && wi + wj < W)) continue;
      state[hi + hj][wi + wj] = true;
    }
  }
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> K;
  REP(hi, H) {
    cin >> S[hi];
  }
    
  int ans = 0;
  REP(hi, H)
    REP(wi, W) 
      if (S[hi][wi] == 'x')
	init(hi, wi);
  
  FOR(hi, K - 1, H - K + 1) {
    FOR(wi, K - 1, W - K + 1) {
      if (!state[hi][wi])
	ans++;
    }
  }

  // printf("%d\n", ans);
  cout << ans << endl;

  return 0;
}

