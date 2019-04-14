#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;cin>>q;
	bitset<64> bs(0);
	
	while(q--){
		int query,i;cin>>query;
		switch(query){
		case 0:
			// test(i)
			// iビット目が立っているか否かを判定する
			cin>>i;
			cout<<(bs.test(i)?1:0)<<endl;
			break;
		case 1:
			// set(i)
			// iビット目を立てる
			cin>>i;
			bs.set(i);
			break;
		case 2:
			// reset(i)
			// iビット目を0にする
			cin>>i;
			bs.reset(i);
			break;
		case 3:
			// flip(i)
			// iビット目を反転する
			cin>>i;
			bs.flip(i);
			break;
		case 4:
			// all(for all)
			// 任意のビットが立っているかを確認する
			cout<<(bs.all()?1:0)<<endl;
			break;
		case 5:
			// any(exists)
			// 立っているビットが存在するかを確認する
			cout<<(bs.any()?1:0)<<endl;
			break;
		case 6:
			// none
			// 任意のビットが0になっているかを確認する
			cout<<(bs.none()?1:0)<<endl;
			break;
		case 7:
			// count
			// 立っているビット数を出力する
			cout<<(bs.count())<<endl;
			break;
		case 8:
			// val
			cout<<(bs.to_ulong())<<endl;
			break;
		}
	}
  return 0;
}
