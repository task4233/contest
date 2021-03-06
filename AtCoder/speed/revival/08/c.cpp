#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<< (x)<<endl;

//
// eratosthenes
//  + 値は1-indexedで格納されている
//  + prime
//    - 素数か否かがbool型で格納
//    - prime[n] ? 素数 : 素数ではない
//  + prime_factorize
//    - 素因数分解をする関数
//    - 引数nを素因数分解して, 
//      どの素数がどれだけ含まれているかをvector< pair<int,int> >で返す 
//    - e.g.) n=20 => (2,2), (5,1)

struct Eratosthenes {
	// 1-indexedで検索可能
  vector< bool > prime;
  // sizeは1e6くらいまでならおk
  Eratosthenes(int _size) {
    init(_size);
  }	
	
  void init(int n) {
    prime.resize(n + 1);
    for(int i=0; i<prime.size(); ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=n; i++) {
      if (prime[i]) {
        for (int j=0; i*(j + 2)<n; ++j) {
					prime[i*(j+2)] = false;
				}
      }
    }
  }

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
};

signed main() {
  int n,p;cin>>n>>p;
  Eratosthenes e(1);
  vector< pair<int,int> > ps = e.prime_factorize(p);
  int ans = 1;
  for(int i=0;i<ps.size();++i){
    if (ps[i].second/n==0) continue;
    for (int j=0;j<ps[i].second/n;++j){
      ans *= ps[i].first;
    }
  }
  cout<<ans<<endl;
  return 0;
}
