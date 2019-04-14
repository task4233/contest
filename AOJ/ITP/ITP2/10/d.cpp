#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector< bitset<64> > mask(n);
	for(int i=0;i<n;++i) {
		int k,kk;cin>>k;
		while(k--) {
			cin>>kk;
			mask[i].set(kk);
		}
	}
	
	int q;cin>>q;
	bitset<64> bs(0);
	
	while(q--){
		int query,i;cin>>query;
		switch(query){
		case 0:
			// test(i)
			// iビット目が立っているか否かを判定する
			cin>>i;
			cout<<(bs.test(i))<<endl;
			break;
		case 1:
			// set(i)
			// マスクと被っているビットを立てる
			cin>>i;
			bs |= mask[i];
			break;
		case 2:
			// reset(i)
			// マスクと被っているビットを0にする
			cin>>i;
			bs &= ~mask[i];
			break;
		case 3:
			// flip(i)
			// マスクと被っているビットを反転する
			cin>>i;
			bs ^= mask[i];
			break;
		case 4:
			// all(for all)
			// 任意のビットが立っているかを確認する
			cin>>i;
			cout<<((bs&mask[i])==mask[i])<<endl;
			break;
		case 5:
			// any(exists)
			// 立っているビットが存在するかを確認する
			cin>>i;
			cout<<((bs&mask[i]).any())<<endl;
			break;
		case 6:
			// none
			// 任意のビットが0になっているかを確認する
			cin>>i;
			cout<<((bs&mask[i]).none())<<endl;
			break;
		case 7:
			// count
			// 立っているビット数を出力する
			cin>>i;
			cout<<((bs&mask[i]).count())<<endl;
			break;
		case 8:
			// val
			cin>>i;
			cout<<((bs&mask[i]).to_ulong())<<endl;
			break;
		}
	}
  return 0;
}
