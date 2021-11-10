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
const int MAX_N = 2e4 + 575;

int N;
int dp[MAX_N];

struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  void init(int n) {
    prime.resize(n + 1);
    REP(i, prime.size()) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i < sqrt(n); i++) {
      if (prime[i]) {
        for (int j = 0; i * (j + 2) < n; j++) {
	  prime[i * (j + 2)] = false;
	}
      }
    }
  }
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  fill_n(dp, MAX_N, -INF);
  
  Eratosthenes e(MAX_N);
  vector< int > primes;
  REP(i, MAX_N) {
    if (e.prime[i])
      primes.emplace_back(i);
  }

  dp[0] = 0;

  REP(i, primes.size()) {
    // bool flag = true;
    RREP(j, N + 1) {
      if (j - primes[i] == 0) {
	dp[j] = max(dp[j], 1);
	// flag = false;
      } else if (j - primes[i] > 0 && dp[j - primes[i]] > 0) {
	dp[j] = max(dp[j], dp[j - primes[i]] + 1);
      }
    }
    /*
    REP(j, 5) {
      debug(dp[j]);
    }
    cout << endl;
    */
  }

  // bool ok = false;
  int ans = 0;
  // REP(i, primes.size())
  {
    ans = max(ans, dp[N]);
    // ok |= dp[i][N];
  }

  // OK(ok);
  if (ans == 0) ans = -1;
  cout << ans << endl;

  /*
  REP(i, 10) {
    REP(j, 10) {
      printf("(%d, %d) = %d\n", i, j, dp[i][j]);
    }
  }
  */
  
  return 0;
}

