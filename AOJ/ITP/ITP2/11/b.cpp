#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	map<int,int> mp;
	for(int i=0;i<k;++i) {
		int j;cin>>j;
		mp[j]++;
	}
	
	for(int bit=0;bit<(1<<n);++bit){
		bool ok= true;
		for(auto &&mi: mp){
			ok &= bit>>mi.first&1;
		}
		if(!ok) continue;
		cout<<bit<<":";
		for(int i=0;i<n;++i){
			if(bit>>i&1) {
				cout<<" "<<i;
			}
		}
		cout<<endl;
	}
  return 0;
}
