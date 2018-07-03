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
const int MAX_N = 1e2 + 1;

int H, W;
string a[MAX_N];

int cnt[26];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> H >> W;
  REP(i, H) {
    cin >> a[i];
    REP(wi, W) {
      cnt[a[i][wi] - 97]++;
    }
  }

  int g1 = ((H & 2) || (W & 2) ? 1 : 0);
  int g2 = H / 2 + W / 2;
  int g3 = H / 2 * W / 2;
  
  REP(i, 26) {
    if (g1 == 0) break;
    if (cnt[i] == 0) continue;
    if (cnt[i] % 4 == 1 || cnt[i] % 4 == 3) {
      cnt[i]--;
      g1--;
    }
  }

  REP(i, 26) {
    if (g2 == 0) break;
    if (cnt[i] == 0) continue;
    if (cnt[i] % 4 == 2) {
      g2--;
      cnt[i] -= 2;
    }
  }

  REP(i, 26) {
    if (g3 == 0) break;
    if (cnt[i] == 0) continue;
    if (cnt[i] % 4 == 0) {
      cnt[i] -= 4;
      g3--;
    }
  }

  bool ok = true;
  REP(i, 26) {
    if (cnt[i] != 0) {
      ok = false;
    }
  }

  OK(ok);

  

  return 0;
}

