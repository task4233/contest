#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64

// x + (n-x)進む
// 次は, x + x進む
// 次は, (n-x-x) + (n-x-x)進む
// 最後に, (n-x-x)進んで終了
// 終了条件は, (n-x-x) * 2 = x
// すなわち, 今の辺の長さのn倍 == x

// 加算されていく様は再帰的
// f(5,2)とした時,
// 2 + (5-2) + f(2,(5-2))
// f(3,2) = 2 + min(3,2) + f(2,(3-2))
// f(2,1) = 1 + 1 + 1(\because 2%1==0)

// 最初だけ特殊で, x + (n-x)とする

int f(int n, int diff){
	int res = 0;
	if (diff ==0) {
		res += 0;
	}else if (n%diff==0){
		res += diff*(n/diff) + diff;
	}else{
		res += n;
		res += min(n, diff);
		res += f(n, abs(n-diff));
	}
	cerr << n << " " << diff << "\n";
	cerr << res << "\n";
	return res;
}

signed main() {
	int n, x;
	cin >> n >> x;

	int ans = x + (n-x) + f(x,n-x);
	cout << ans << endl;

	//cout << 3%6 << endl;
	//cout << 4%6 << endl;

	
  return 0;
}
