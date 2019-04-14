#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	a.push_back(1e9+1);
	
	int q;cin>>q;
	while(q--){
		int k;cin>>k;
		cout<<(lower_bound(a.begin(),a.end(),k) - a.begin())<<" "<<(upper_bound(a.begin(),a.end(),k) - a.begin())<<endl;
	}
  return 0;
}
