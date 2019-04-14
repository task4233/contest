#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;

	for(int bit=0;bit<(1<<n);++bit){
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
