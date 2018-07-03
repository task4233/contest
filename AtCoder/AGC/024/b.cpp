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
const int MAX_N = 2e5 + 575;

int N;

int incMemo[MAX_N];
int decMemo[MAX_N];

int p[MAX_N];
int data[MAX_N];

int getInc(int n) {
  if (incMemo[n] > 0) return incMemo[n];
  if (n == N) return 0;
  
  int res = 0;
  if (data[n + 1] > data[n]) {
    res += getInc(n + 1);
  }
  /*
  FOR(i, data[n], N) {
    if (p[i] == n + 1) {
      res += getInc(n + 1);
      break;
    }
  }
  */

  return incMemo[n] = res + 1;
}

int getDec(int n) {
  if (decMemo[n] > 0) return decMemo[n];

  if (n == 0) return 0;
  int res = 0;
  if (data[n - 1] < data[n]) {
    res += getDec(n - 1);
  }
  
  /*
  RREP(i, data[n]) {
    if (p[i] == n - 1) {
      res += getDec(n - 1);
      break;
    }
  }
  */

  return decMemo[n] = res + 1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) {
    cin >> p[i];
    p[i]--;
    data[p[i]] = i;
  }

  memset(incMemo, -1, sizeof(incMemo));
  memset(decMemo, -1, sizeof(decMemo));
  
  RREP(i, N) {
    getInc(i);
  }

  REP(i, N) {
    getDec(i);
  }

  int ans = -1;
  REP(i, N) {
    ans = max(ans, incMemo[i]);
    ans = max(ans, decMemo[i]);
  }

  
  ans = N - ans;
  cout << ans << endl;
  // cout << ans << endl;
  // debug(N - ans);

  /*
  REP(i, N) {
    printf("inc[%d] : %d\n", i, incMemo[i]);
  }

  printf("\n");
  REP(i, N) {
    printf("dec[%d] : %d\n", i, decMemo[i]);
  }
  */

  return 0;
}

