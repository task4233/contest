#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t a,b;cin>>a>>b;
	bitset<32> bit_a(a), bit_b(b);

	cout<<(bit_a&bit_b)<<endl;
	cout<<(bit_a|bit_b)<<endl;
	cout<<(bit_a^bit_b)<<endl;
  return 0;
}
