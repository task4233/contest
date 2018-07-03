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

const int INF = 1e9 + 1;
const int MAX_N = 3e5 + 1;

int N;
string s;

// 0:w, 1:e
int memo[MAX_N][2];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  cin >> s;

  int ans = 0;
  int eCnt, wCnt;
  eCnt = wCnt = 0;
  REP(i, N) {
    // e
    if (s[i] == 'E') eCnt++;
    if (s[i] == 'W') wCnt++; 
  }

  ans = min(eCnt, wCnt);

  REP(i, N) {
    if (i > 0) {
      memo[i][0] += memo[i - 1][0];
      memo[i][1] += memo[i - 1][1];
    }
    if (s[i] == 'W') {
      memo[i][0]++;
    } else {
      memo[i][1]++;
    }
  }

  REP(i, N) {
    int tmp = 0;
    tmp += memo[i][0];
    tmp += memo[N - 1][1] - memo[i][1];

    ans = min(ans, tmp);
  }

  cout << ans << endl;
  

  return 0;
}
