#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	int m;cin>>m;
	vector<int> b(m);
	for(int i=0;i<m;++i)cin>>b[i];

	vector<int> ans;
	set_difference(begin(a),end(a),begin(b),end(b),inserter(ans, end(ans)));

	for(auto &&ai: ans){
		cout<<ai<<endl;
	}
  return 0;
}
