#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector< pair<int,int> > d(n);
	for(int i=0;i<n;++i) cin>>d[i].first>>d[i].second;

	sort(d.begin(),d.end(), [](auto &d1, auto &d2){
			if(d1.first==d2.first) return d1.second < d2.second;
			return d1.first < d2.first;
		});

	for(auto &&di: d){
		cout<<di.first<<" "<<di.second<<endl;
	}
  return 0;
}
