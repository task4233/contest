#include <bits/stdc++.h>
using namespace std;

void out(vector<int> a){
		bool isFirst = true;
		for(auto &&ai: a){
			if(!isFirst) cout<<" ";
			cout<<ai;
			isFirst &= false;
		}
		cout<<endl;;	
}


int main() {
	int n;cin>>n;
	vector<int> par(n);
	iota(par.begin(),par.end(),1);
	
	do {
		out(par);
	} while(next_permutation(par.begin(),par.end()));
  return 0;
}
