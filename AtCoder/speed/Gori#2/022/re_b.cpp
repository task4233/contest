#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64
//   _
//  //
// //
// ￣

int f(int x, int y){
	int mx = max(x, y);
	int mn = min(x, y);
	if (mx % mn == 0) return (mx/mn)*mn*2 - mn;
	return f(mn, mx%mn) + (mx/mn)*mn*2;
}

signed main() {
	int n, x;
	cin >> n >> x;
	cout << n + f(x, n-x) << endl;
  return 0;
}
