#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t a,b,c, ans = 0;
	cin >> a >> b >> c;
	(ans = (a * b % (int64_t)(1e9+7)) * c) %= (int64_t)(1e9+7);
	cout << ans << endl;
  return 0;
}
