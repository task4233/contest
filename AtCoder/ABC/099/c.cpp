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

int N;

int memo[MAX_N];

int solve() {
  if (memo[N] > 0) {
    return memo[N];
  }

  
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< int > list;
  list.emplace_back(1);
  int s = 6;
  int n = 9;
  FOR(i, 1, MAX_N) {
    if (s < MAX_N) {
      list.emplace_back(s);
      s *= 6;
    }
    if (n < MAX_N) {
      list.emplace_back(n);
      n *= 9;
    }
  }


  sort(ALL(list));
  // debug(list.size());


  int ans = INF;
  FOR(bit, 1, (1 << list.size())) {
    int sm = 0;
    int cnt = 0;
    REP(i, list.size()) {
      if ((bit >> i) & 1) {
	sm += list[i];
	cnt++;
      }
    }
    if (sm > MAX_N) continue;
    memo[sm] = cnt;
  }

  FOR(i, 1, MAX_N) {
    if (memo[i] > 0) continue;
    int tmp = INF;
    EACH(li, list) {
      if (i < li) break;
      if (memo[i - li] > 0) {
	tmp = min(tmp, memo[i - li] + 1);
      }
    }
    int cnt = 0;
    memo[i] = min(tmp, memo[i - 1] + 1);
  }
  

  ans = memo[N];
  cout << ans << endl;
  
  /*
  int ans = 0;
  int current = list.size() - 1;
  while(N > 0) {
    if (list[current] <= N) {
      ans++;
      N -= list[current];
    } else {
      current--;
    }
    cout << N << endl;
  }
  cout << ans << endl;
*/

  return 0;
}

