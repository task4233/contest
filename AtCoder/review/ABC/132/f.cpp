#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

constexpr int MOD = 1e9+7;

vector< pair< int, int > > prime_factorize(int n) {
  vector< pair< int, int > > res;
  for (int p=2; p*p<=n; ++p) {
    if (n%p != 0) continue;
    int num = 0;
    while (n%p == 0) ++num, n /= p;
    res.push_back(make_pair(p, num));
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}


signed main(){
  int n,k; cin>>n>>k;

  vector< pair<int,int> > factrized = prime_factorize(n);

  int ans=1;
  for(int ki=0;ki<(k+1)/2;++ki){
    int tmp = 0;
    for(auto &&fi: factrized){
      int i = fi.first;
      // (lb, ub]の半開区間
      int lb=n/(i+1), ub=n/i;
      tmp += (ub-lb)*i%MOD;
    }
    (ans *= tmp) %= MOD;
  }
  cout<<ans<<endl;
}
