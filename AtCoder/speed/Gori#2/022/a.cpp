#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> l(2*n);
	for(int i=0;i<2*n;++i)cin >>l[i];
	sort(l.begin(), l.end());
	int ans =0;
	for(int i=1;i<2*n; i+=2){
		int len = min(l[i], l[i-1]);
		ans += len;
	}
	cout << ans << endl;
  return 0;
}
