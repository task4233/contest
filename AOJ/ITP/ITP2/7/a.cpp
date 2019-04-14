#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;

	set<int> st;
	while(q--){
		int query,y;cin>>query>>y;
		if(query==0){
			// insert
			st.insert(y);
			cout<<st.size()<<endl;
		}else{
			cout<<(st.find(y)!=st.end()?1:0)<<endl;
		}
	}
  return 0;
}
