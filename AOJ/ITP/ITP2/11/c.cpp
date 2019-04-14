#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	vector<int> b(n);
	for(int i=0;i<k;++i) cin>>b[i];
	
	for(int bit=0;bit<(1LL<<k);++bit){
		bitset<64> bs(0);
		for(int i=0;i<k;++i){
			if(bit>>i&1) bs.set(b[i]);
		}
		cout<<bs.to_ulong()<<":";

		for(int i=0;i<k;++i){
			if(bit>>i&1) {
				cout<<" "<<b[i];
			}
		}
		cout<<endl;
	}
  return 0;
}
