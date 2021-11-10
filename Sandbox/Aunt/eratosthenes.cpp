// ------------------------------------
// Date:2018/ 3/21
// Problem:エラトステネスの篩  eratosthenes.cpp
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
static const ll MAX_LN = 1e18 + 1;

bool isPrime[MAX_LN];

void eratosthenes()
{
  memset(isPrime, true, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  FOR(i, 2, MAX_LN) {
    for(int j = i * 2; j < MAX_LN; j += i) {
      isPrime[j] = false;
    }
  }
}

int main()
{
  eratosthenes();
  CIN(N);
  int ans = 0;
  REP(i, N + 1) if (isPrime[i]) ans++;

  cout << ans << endl;
  
  return 0;
}

