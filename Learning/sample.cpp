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

struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  init(int n) {
    prime.resize(n + 1);
    memset(prime, false, sizeof(prime));
    for(int i = 2; i < sqrt(n); i++)
      if (prime[i])
        for (int j = 0; i * (j + 2) < N; j++)
	  prime[i * (j + 2)] = false;
  }
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  

  return 0;
}

