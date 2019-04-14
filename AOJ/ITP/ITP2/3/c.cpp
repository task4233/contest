#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	int q;cin>>q;
	while(q--){
		int b,e,k;cin>>b>>e>>k;
		cout<<count(next(a.begin(),b),next(a.begin(),e),k)<<endl;
	}
  return 0;
}
