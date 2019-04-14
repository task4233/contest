#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){return (a%b==0?b:gcd(b,a%b));}

int main() {
	int n,X;cin>>n>>X;
	vector<int> x(n),dist(n);
	for(int i=0;i<n;++i) {
		cin>>x[i];
		dist[i] = abs(X-x[i]);
	}

	int mx=dist[0];
	for(int i=0;i<n;++i) mx=gcd(mx,dist[i]);

	cout<<mx<<endl;
	
  return 0;
}
