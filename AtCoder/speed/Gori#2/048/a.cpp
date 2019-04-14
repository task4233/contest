#include <iostream>
using namespace std;

int main() {
	int64_t a,b,c,k;
	cin>>a>>b>>c>>k;

	if(abs(a-b)>1e18) {
		cout<<"Unfair"<<endl;
		return 0;
	}

	cout<<((k%2?-1:1)*(a-b))<<endl;
  return 0;
}
