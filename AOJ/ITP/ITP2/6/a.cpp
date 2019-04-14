#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	int q;cin>>q;
	while(q--){
		int k;cin>>k;
		cout<<(binary_search(a.begin(),a.end(),k)?1:0)<<endl;
	}
  return 0;
}
