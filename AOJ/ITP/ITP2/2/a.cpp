#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q;cin>>n>>q;
	stack<int> st[1010];

	while(q--){
		int query,t;cin>>query>>t;
		if(query==0){
			int x;cin>>x;
			st[t].push(x);
		}else if(query==1){
			if(st[t].empty()) continue;
			cout<<st[t].top()<<endl;
		}else{
			if(st[t].empty()) continue;
			st[t].pop();
		}
	}
	
  return 0;
}
