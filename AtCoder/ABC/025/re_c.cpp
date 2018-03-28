
// ------------------------------------
// Date:2018/ 3/28
// Problem:C - 双子と○×ゲーム re_c.cpp
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

// m[i][j]: Chokudai(1) : Naoko(2)
int m[3][3];
int b[2][3];
int c[3][2];

int solve(int cnt)
{
  if (cnt == 9) {
    // 全て埋められてるとき(i, 2) {
      REP(j, 3) {
	if (m[i][j] == m[i + 1][j]) res += b[i][j];
	else res -= b[i][j];
      }
    }

    REP(i, 3) {
      REP(j, 2) {
	if (m[i][j] == m[i][j + 1]) res += c[i][j];
	else res -= c[i][j];
      }
    }
    return res;
  }

  
  if (cnt & 1) {
    int m_min = INF;
    // Naoko
    REP(i, 3) {
      REP(j, 3) {
	if (m[i][j] == 0) {
	  m[i][j] = 2;
	  m_min = min(m_min, solve(cnt + 1));
	  m[i][j] = 0;
	}
      }
    }
    return m_min;
  }
  
  int m_max = -INF;
  // Chokudai
  REP(i, 3) {
    REP(j, 3) {
      if (m[i][j] == 0) {
	m[i][j] = 1;
	m_max = max(m_max, solve(cnt + 1));
	m[i][j] = 0;
      }
    }
  }
  return m_max;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int sum = 0;
  
  REP(i, 2) {
    REP(j, 3) {
      cin >> b[i][j];
      sum += b[i][j];
    }
  }

  REP(i, 3) {
    REP(j, 2) {
      cin >> c[i][j];
      sum += c[i][j];
    }
  }

  memset(m, 0, sizeof(m));

  // OK(true)
  int res = solve(0);
  // OK(false);

  /*
  debug(sum);
  debug(res);
  */
  int Chokudai = (sum + res) / 2;
  int Naoko = sum - Chokudai;

  cout << Chokudai << endl;
  cout << Naoko << endl;
  
  return 0;
}

