#include <bits/stdc++.h>
using namespace std;

// dp[si][ti] := si文字目とti文字目までのLCS
int dp[3030][3030];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
	string s, t;
	cin >> s >> t;
	
	for (int si=0; si<s.size(); ++si) {
		for (int ti=0; ti<t.size(); ++ti) {
			if (s[si] == t[ti]) {
				dp[si+1][ti+1] = dp[si][ti] + 1;
			} else {
				dp[si+1][ti+1] = max(dp[si][ti+1], dp[si+1][ti]);
			}
		}
	}
	cout << dp[s.size()][t.size()] << endl;

	string ans = "";
	int si=0, ti=0, last = 0;
	queue< pair< int, int > > q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		if (last == dp[s.size()][t.size()]) break;
		tie(si, ti) = q.front(); q.pop();
		for (int i=0; i<2; ++i) {
			int ns = si + dx[i];
			int nt = ti + dy[i];
			if (dp[ns][nt] > last) {
				ans += s[ns-1];
				cout << "t: " << nt-1 << endl;
				cout << "s: " << ns-1 << endl;
				last = dp[ns][nt];
			}
			q.push(make_pair(ns, nt));
		}
	}
	cout << ans << endl;
	
	for (int si=0; si<=s.size(); ++si){
		for (int ti=0; ti<=t.size(); ++ti) {
			cout << dp[si][ti] << " ";
		}
		cout << endl;
	}
	
  return 0;
}
