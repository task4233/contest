#include <bits/stdc++.h>
using namespace std;
using PAIR = pair< int, int >;

int main(){
	int n; cin >> n;
	vector< PAIR > d(n);
	for(int i=0; i<n; ++i) cin>>d[i].first>>d[i].second;

	// dの1つ目の要素で昇順ソート
	sort(d.begin(), d.end(), [](PAIR p1, PAIR p2){
		if(p1.first == p2.first) return p1.second < p2.second;
		return p1.first < p2.first;
	});

	// bはdの2つ目の要素のみを格納するためのvector
	// (dの1つ目の要素が重複している時, 2つ目の要素が小さいものを採用)
	vector< int > b;
	for(int i=0; i<n; ++i){
		if(i>0 && d[i].first == d[i-1].first) continue;
		b.push_back(d[i].second);
	}

	// 作った要素でLISを求める
	vector< int > dp(b.size(), 1e9+1);
	for(int i=0; i<b.size(); ++i){
		*lower_bound(dp.begin(), dp.end(), b[i]) = b[i];
	}

	int ans = lower_bound(dp.begin(), dp.end(), 1e9+1) - dp.begin();
	cout << ans << endl;
}
