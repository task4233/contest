#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q;cin>>n>>q;
	vector<int> v[1010];

	while(q--){
		int query,t;cin>>query>>t;
		if(query==0){
			int x;cin>>x;
			v[t].push_back(x);
		}else if(query==1){
			for(int i=0;i<v[t].size();++i){
				cout<<v[t][i];
				if(i<v[t].size()-1) cout<<" ";
			}
			cout<<endl;
		}else{
		  v[t].clear();
		}
	}
	
  return 0;
}
