#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	int m;cin>>m;
	vector<int> b(m);
	bool ok = true;
	for(int i=0;i<m;++i){
		cin>>b[i];
		ok &= binary_search(a.begin(),a.end(),b[i]);
	}
	cout<<(ok?1:0)<<endl;
  return 0;
}
