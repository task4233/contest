// ------------------------------------
// Date:2018/ 4/ 3
// Problem:2017likenumber / / b.cpp
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

int Q;

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

  Eratosthenes e(MAX_N);
  vector< ll > likeNum(MAX_N, 0ll);
  FOR(i, 1, MAX_N) {
    likeNum[i] = likeNum[i - 1];
    if (e.prime[i] && e.prime[(i + 1) / 2]) likeNum[i]++;
  }

  cin >> Q;
  REP(i, Q) {
    CIN(l, r);
    ll ans = likeNum[r] - likeNum[l - 1];
    cout << ans << endl;
  }
  

  return 0;
}

