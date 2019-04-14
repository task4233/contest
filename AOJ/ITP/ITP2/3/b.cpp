#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i) cin>>a[i];

	int q;cin>>q;
	while(q--){
		int com,l,u;cin>>com>>l>>u;
		if(com==0){
			cout<<(*minmax_element(next(a.begin(),l),next(a.begin(),u)).first)<<endl;
		}else{
			cout<<(*minmax_element(next(a.begin(),l),next(a.begin(),u)).second)<<endl;
		}
	}
  return 0;
}
