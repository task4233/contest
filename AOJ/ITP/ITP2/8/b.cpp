#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;
	map<string,int> mp;
	
	while(q--){
		int query;string key;cin>>query>>key;
		if(query==0){
			int x;cin>>x;
			mp[key]=x;
		}else if(query==1){
			cout<<mp[key]<<endl;
		}else{
			mp[key] = 0;
		}
	}
  return 0;
}
