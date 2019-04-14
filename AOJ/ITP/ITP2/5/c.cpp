#include <bits/stdc++.h>
using namespace std;

void out(vector<int> a){
		bool isFirst = true;
		for(auto &&ai: a){
			if(!isFirst) cout<<" ";
			cout<<ai;
			isFirst &= false;
		}
		cout<<endl;;	
}

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];

	vector<int> prev(a), nx(a);
	prev_permutation(prev.begin(),prev.end());
	if(lexicographical_compare(prev.begin(),prev.end(),a.begin(),a.end())) out(prev);
	out(a);
	next_permutation(nx.begin(),nx.end());
	if(lexicographical_compare(a.begin(),a.end(),nx.begin(),nx.end())) out(nx);
	return 0;
}
