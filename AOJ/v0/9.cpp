#include <bits/stdc++.h>
using namespace std;

struct Eratosthenes {
	// 1-indexedで検索可能
  vector< bool > prime;
  Eratosthenes(int _size) {
		// サイズが小さいとバグるので, 10倍しておく
    init(_size * 10);
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

	// 整数nを素因数分解して, その要素がいくつあるかを返す
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

int main() {
	int n=30;
	Eratosthenes e(1010101);
	while(n--){
		int k;cin>>k;
		int ans=0;
		for(int i=1;i<=k;++i){
			if(e.prime[i]) {
				++ans;
				cerr << "i;" << i <<endl;
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}
