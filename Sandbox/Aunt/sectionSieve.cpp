// ------------------------------------
// Date:2018/ 3/21
// Problem:区間篩 section sieve sectionSieve.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1e6 + 1;
static const ll MAX_L = 1e12 + 1;

bool isPrimeSmall[MAX_N];
bool isPrime[MAX_L];

// 区間[a, b)の素数列挙
void section_sieve(ll a, ll b)
{
  REP(i, sqrt(b)) isPrimeSmall[i] = true;
  REP(i, b - a) isPrime[i] = true;

  for (int i = 2; (ll)i * i < b; ++i) {
    if (isPrimeSmall[i]) {
      for (int j = 2 * i; j < b; j += i) isPrimeSmall[j] = false;
      for (ll j = max(2ll, (a + i - 1) / i) * i; j < b; j += i) isPrime[j - a] = false;
    }
  }
}

int main()
{
  LCIN(M, N);
  section_sieve(M, N);
  int ans = 0;
  REP(i, N - M) {
    if (isPrime[i]){
      ans++;
      // debug(i + M);
    }
  }

  cout << ans << endl;
  return 0;
}

