#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;
	multimap<string,int> mp;
	mp.insert(make_pair("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", 1));
	
	while(q--){
		int query;string key;cin>>query>>key;
		if(query==0){
			int x;cin>>x;
			mp.insert(make_pair(key,x));
		}else if(query==1){
			auto lb = mp.lower_bound(key), ub=mp.upper_bound(key);
			for(auto it=lb;it!=ub;++it) {
				if(it->second == 0) continue;
				cout<<it->second<<endl;
			}
		}else if(query==2){
			mp.erase(key);
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
