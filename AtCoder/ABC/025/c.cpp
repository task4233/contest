// ------------------------------------
// Date:2018/ 3/27
// Problem:C - 双子と○×ゲーム c.cpp
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
const int MAX_N = 1e5 + 1;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int b[2][3];
int c[3][2];
// 1:o(C) / 2:x(N)
int m[3][3];

int result()
{
  // 先手 - 後手
  int score = 0;

  REP(i, 2)
    REP(j, 3)
      score += m[i][j] == m[i + 1][j] ? b[i][j] : -b[i][j];

  REP(i, 3)
    REP(j, 2)
      score += m[i][j] == m[i][j + 1] ? c[i][j] : -c[i][j];

  return score;
}

int dfs(int cnt) {
  if (cnt == 9) return result();

  if (cnt % 2 == 0) {
    // 先手
    int mx = -INF;
    REP(i, 3) {
      REP(j, 3) {
	if (m[i][j] == -1) {
	  m[i][j] = 1;
	  mx = max(mx, dfs(cnt + 1));
	  m[i][j] = -1;
	}
      }
    }
    return mx;
  }

  int mi = INF;
  REP(i, 3) {
    REP(j, 3) {
      if (m[i][j] == -1) {
	m[i][j] = 0;
	mi = min(mi, dfs(cnt + 1));
	m[i][j] = -1;
      }
    }
  }
  return mi;
}

int main()
{
  int sum = 0;
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  REP(hi, 2) 
    REP(wi, 3) {
    cin >> b[hi][wi];
    sum += b[hi][wi];
  }
  REP(hi, 3)
    REP(wi, 2) {
    cin >> c[hi][wi];
    sum += c[hi][wi];
  }

  memset(m, -1, sizeof(m));

  int score = dfs(0);
  int N = (sum - score) / 2;
  int C = sum - N;
  cout << C << endl;
  cout << N << endl;
  
  return 0;
}

