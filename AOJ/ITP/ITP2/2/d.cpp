#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q;cin>>n>>q;
	list<int> li[1010];
	
	while(q--){
		int query;cin>>query;
		if(query==0){
			int t,x;cin>>t>>x;
			li[t].push_back(x);
		}else if(query==1){
			int t;cin>>t;
			bool isFirst = true;
			for(auto &&lj: li[t]){
				if(!isFirst) cout << " ";
				cout<<lj;
				isFirst &= false;
			}
			cout<<endl;
		}else{
			int s,t;cin>>s>>t;
			li[t].splice(li[t].end(), move(li[s]));
			li[s].clear();
		}
	}
  return 0;
}

