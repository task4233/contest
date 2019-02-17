#include <bits/stdc++.h>
using namespace std;

#define ALL(a) (a).begin(), (a).end()
#define debug(x) cerr<<#x<<":"<< (x)<<endl

// dp[i] := i本使って作れる数値の最大値(stringで持つ)
// 遷移
// dp[i] = max(dp[i], dp[i-cost[a[j]]] + a[j])

string dp[101010];
int cost[9]={2,5,5,4,5,6,3,7,6};

int main() {
	int n,m; cin>>n>>m;
	vector<int> a(m);
	for(int i=0;i<m;++i)cin>>a[i];
	sort(ALL(a));
	reverse(ALL(a));

	fill_n(dp,n,"0");
	dp[0]="";
	int sm=0;
	for(int i=0;i<=n;++i){
		for(auto &&ai: a){
			//cerr<<"fuge"<<endl;
			if (i-cost[ai-1]<0) continue;
			if (dp[i-cost[ai-1]]=="0") continue;
			//debug(i);
			//debug(ai);
			string tmp = to_string(ai) + dp[i-cost[ai-1]];
			//cerr<<"hoge"<<endl;
			//debug(cost[ai-1]);
			//cerr<<tmp<< endl<<endl;
			if(dp[i].size() > tmp.size()) continue;
			if(dp[i].size() == tmp.size()) {
				if(dp[i]>tmp) continue;
			}
			//cerr<<tmp<< endl;
			dp[i] = tmp;
			//cerr<<tmp<< endl;
		}
	}
	string ans = dp[n];
	sort(ALL(ans));
	reverse(ALL(ans));
	cout << ans << endl;
  return 0;
}

