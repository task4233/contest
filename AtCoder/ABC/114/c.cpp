#include <iostream>
#include <string>
using namespace std;
using int64 = int_fast64_t;

int N;
char opt[3] = {'7', '5', '3'};

bool check(string str) {
	// t:three, f:five, s:seven
	bool t = false, f = false, s = false;
	for (int i=0; i<str.size(); ++i) {
		t |= (str[i] == '3');
		f |= (str[i] == '5');
		s |= (str[i] == '7');
	}
	return t && f && s;
}

int solve(string sum) {
	// 範囲外の時は0, 空の時はスルー
	if (sum.size() == 0);
  else if (sum.size() > 9) return 0;
	else if (stoi(sum) > N) return 0;
	
	int ret = 0;
	for (int i=0; i<3; ++i) {
		string tmp = sum + opt[i];

		// 範囲内で753全てを利用している時に1を加算
		if (tmp.size() <= 9 && stoi(tmp) <= N && check(tmp)) {
			ret++;
		}
		ret += solve(tmp);
	}

	return ret;
}

int main() {
	cin >> N;

	int ans = solve("");
	cout << ans << endl;
	
	return 0;
}
