#include <bits/stdc++.h>
using namespace std;

int main() {
	double N;
	cin >> N;

	double L = 1e9;
	double d = L/N;
	int ans = 0;
	for (int hi = 0; hi < N; ++hi) {
		for (int wi = 0; wi < N; ++wi) {

			bool ok = true;
			for (int hj = 0; hj < 2; ++hj) {
				for (int wj = 0; wj < 2; ++wj) {
					double x = L/2.0 - abs(L/2.0 - (double)(wi + wj) * d);
					double y = L/2.0 - abs(L/2.0 - (double)(hi + hj) * d);
					ok &= (abs(L/2.0 - (double)(hi + hj) * d) <= x &&
								 abs(L/2.0 - (double)(wi + wj) * d) <= y);
				}
			}
			if (ok) ans++;
		}
	}
	cout << ans << endl;
}
