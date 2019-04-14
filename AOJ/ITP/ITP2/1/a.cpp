#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;

	vector<int> v;
	while(q--){
		int query;cin>>query;
		if(query==0){
			//pb
			int x;cin>>x;
			v.push_back(x);
		}else if(query==1){
			//random access
			int p;cin>>p;
			cout<<v[p]<<endl;
		}else{
			v.pop_back();
		}
	}
	
  return 0;
}
