#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

// editorial(りんごさん)
// a,b,c,d,eという5つのゴミがあるとする
// この時, 遠い方から拾っていったほうが良いのはわかる
// a, b, c, d, eを拾うためのコストは次のようになる
//  (2^2+1)(e-d) + (3^2+1)(d-c) + (4^2+1)(c-b) + (5^2+1)(b-a) + (6-2+1)a
// = 5e + 5d + 7c + 9b + 11a
// ここで, 5(e+d) + 7c + 9b + 11a
// という風に最初の二項以降は2ずつ増えていることがわかる
//
// ここで, 1度に拾う個数を決めておけば, その部分をまとめて拾えることがわかる
//
// editorial 前計算
// 累積和により, 求めることが可能
// 差分を考えることで, 累積和で求められる
// 差分の増加は
// (k+1)^2*x - k^2*x = (2*k+1)*x
// であるから, 差分を考えることで実装可能

signed main() {
	int n,x; cin>>n>>x;
	vector<int> a(n);
	for(int i=0;i<n;++i) cin>>a[i];

  vector<int> sm(n+1,0);
  for(int i=0;i<n;++i) {
    sm[i+1] += sm[i] + a[i];
  }
  
	auto _cost = [&](int k) {
                 int res=0, now=n;
                 res += 5*sm[now];
                 now -= k*2;
                 while (now > 0) {
                   // オーバーフロー対策
                   if(numeric_limits<int>::max()-res < sm[now]*2) {
                     return (1LL<<60);
                   }
                   res += sm[now]*2;
                   now -= k;
                 }
                 return res;
               };
	
	int ans = 1LL<<60;
	// kは分割数
	for(int k=1;k<=n;++k) {
		ans = min(ans, _cost(k) + k*x);	
	}
	ans += n * x;
	cout<<ans<<endl;
  return 0;
}
