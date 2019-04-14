#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	int q;cin>>q;
	while(q--){
		int b,e,t;cin>>b>>e>>t;
		swap_ranges(next(a.begin(),b), next(a.begin(),e), next(a.begin(),t));
	}

	bool isFirst=true;
	for(auto &&ai: a){
		if(!isFirst) cout<<" ";
		cout<<ai;
		isFirst &= false;
	}
	cout<<endl;
  return 0;
}
