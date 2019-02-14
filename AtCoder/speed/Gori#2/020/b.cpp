#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = n;
	for (int i=0; i<=n; ++i){
		for(int j=0; j<=n; ++j) {
			if (i*j > n) break;
			ans = min(ans, (n-j*i)+abs(j-i));
		}
	}
	cout << ans << endl;
  return 0;
}
