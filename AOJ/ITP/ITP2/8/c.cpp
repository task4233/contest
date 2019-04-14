#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;
	map<string,int> mp;
	mp["zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"]++;
	
	while(q--){
		int query;string key;cin>>query>>key;
		if(query==0){
			int x;cin>>x;
			mp[key]=x;
		}else if(query==1){
			cout<<mp[key]<<endl;
		}else if(query==2){
			mp[key] = 0;
		}else{
			string r;cin>>r;
			for(auto it=mp.lower_bound(key);it!=mp.upper_bound(r);++it){
				if((*it).second == 0) continue;
				cout<<((*it).first) << " " << ((*it).second)<<endl;
			}
		}
	}
  return 0;
}
