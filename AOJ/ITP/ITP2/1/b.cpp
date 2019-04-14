#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;

	deque<int> dq;
	while(q--){
		int query;cin>>query;
		if(query==0){
			// push
			int d,x;cin>>d>>x;
			if(d==0) {
				dq.push_front(x);
			}else{
				dq.push_back(x);
			}
		}else if(query==1){
			// randomaccess
			int p;cin>>p;
			cout<<dq[p]<<endl;
		}else{
			int d;cin>>d;
			if(d==0)dq.pop_front();
			else dq.pop_back();
		}
	}
  return 0;
}
