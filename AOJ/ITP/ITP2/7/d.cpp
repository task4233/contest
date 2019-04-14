#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;

	multiset<int> st;
	st.insert(1e9+1);
	while(q--){
		int query,y;cin>>query>>y;
		if(query==0){
			// insert
			st.insert(y);
			cout<<(st.size()-1)<<endl;
		}else if(query==1){
			cout<<st.count(y)<<endl;
		}else if(query==2){
			st.erase(y);
		}else{
			int r;cin>>r;
			for(auto it=st.lower_bound(y);it!=st.upper_bound(r);++it){
				cout<<*it<<endl;
			}
		}
	}
  return 0;
}
