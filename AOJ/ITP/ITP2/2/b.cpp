#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,q;cin>>n>>q;
	queue<int> que[1010];
	
	while(q--){
		int query,t;cin>>query>>t;
		if(query==0){
			int x;cin>>x;
			que[t].push(x);
		}else if(query==1){
			if(que[t].empty()) continue;
			cout<<que[t].front()<<endl;
		}else{
			if(que[t].empty()) continue;
			que[t].pop();
		}
	}
  return 0;
}
