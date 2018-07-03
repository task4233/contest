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
const int MAX_N = 575;
const int MAX_C = 77;

int N, C;
int D[MAX_C][MAX_C];
int c[MAX_N][MAX_N];

// mod3の数字列をMAX_Nに変更する時にかかるコスト
int memo[3][MAX_C];

// mod3の数字列のデータ
vector< int > data[3];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> C;
  REP(hi, C) {
    REP(wi, C) {
      cin >> D[hi][wi];
    }
  }

 
  REP(hi, N) {
    REP(wi, N) {
      CIN(a);
      data[(hi + wi) % 3].emplace_back(a - 1);
      // cin >> c[hi][wi];
    }
  }

  REP(h, 3) {
    REP(i, C) {
      int tmp = 0;
      EACH(di, data[h]) {
	tmp += D[di][i];
      }
      memo[h][i] = tmp;
    }
  }


  int ans = INF;
  REP(h, C) {
    REP(i, C) {
      if (h == i) continue;
      REP(j, C) {
	if (h == j or i == j) continue;
	ans = min(ans, memo[0][h] + memo[1][i] + memo[2][j]);
	/*
	if (ans == memo[0][h] + memo[1][i] + memo[2][j]) {
	  debug(h);
	  debug(i);
	  debug(j);
	  cout << ans << endl;
	}
	*/
      }
    }
  }

  cout << ans << endl;

  /*
  REP(i, 3) {
    debug(i);
    EACH(di, data[i]) {
      debug(di);
    }
    cout << endl;
    REP(ci, C) {
      debug(ci);
      debug(memo[i][ci]);
    }
    cout << endl;
  }
  */

  return 0;
}

