#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	a.erase(unique(a.begin(),a.end()), a.end());
	
	bool isFirst=true;
	for(auto &&ai: a){
		if(!isFirst) cout<<" ";
		cout<<ai;
		isFirst &= false;
	}
	cout<<endl;
  return 0;
}
