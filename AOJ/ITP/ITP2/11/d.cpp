#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;cin>>n>>k;

	for(int bit=0;bit<(1<<n);++bit){
		int cnt=0;
		for(int i=0;i<n;++i){
			if(bit>>i&1)++cnt;
		}
		if(cnt != k) continue;

		bitset<64> bs(0);
		for(int i=0;i<n;++i){
			if(bit>>i&1) bs.set(i);
		}
		cout<<bs.to_ulong()<<":";

		for(int i=0;i<n;++i){
			if(bit>>i&1) {
				cout<<" "<<i;
			}
		}
		cout<<endl;
	}
  return 0;
}
