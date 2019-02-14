#include <bits/stdc++.h>
using namespace std;

int main() {
	// a < b
	int a, b;
	cin >> a >> b;
	if (a > 0) cout << "Positive" << endl;
	// a <= 0
	else if (b > 0) cout << "Zero" << endl;
	else cout << (a - b + 1 & 1 ? "Negative" : "Positive")  << endl;
  return 0;
}

