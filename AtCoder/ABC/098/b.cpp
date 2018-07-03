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
const int MAX_N = 1e3 + 1;

int N;
string s;

int cnt[MAX_N][26];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  cin >> s;

  REP(i, N) {
    if (i > 0) {
      REP(j, 26) {
	cnt[i][j] += cnt[i - 1][j];
      }
    }
    cnt[i][s[i] - 97]++;
  }

  int ans = 0;
  
  REP(i, N) {
    int tmp = 0;
    REP(j, 26) {
      if (cnt[i][j] > 0 && cnt[N - 1][j] - cnt[i][j] > 0) {
	tmp++;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
