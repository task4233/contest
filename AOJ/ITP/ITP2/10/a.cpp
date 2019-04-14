#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t x;cin>>x;
	// そのまま出力
	bitset<32> bs(x);
	cout<<bs<<endl;

	// ビット反転して出力
	bitset<32> rev_bs = ~bs;
	cout<<rev_bs<<endl;

	// 左シフトして出力
	bitset<32> lshift_bs = bs << 1;
	cout<<lshift_bs<<endl;

	// 右シフトして出力
	bitset<32> rshift_bs = bs >> 1;
	cout<<rshift_bs<<endl;
	
  return 0;
}
