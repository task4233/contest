#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;cin>>n;
	vector< tuple<int,int,char,int64_t, string> > dd(n);
	for(int i=0;i<n;++i) {
		int u,w;
		char t;
		int64_t d;
		string s;cin>>u>>w>>t>>d>>s;
		dd[i] = make_tuple(u,w,t,d,s);
	}

	sort(dd.begin(),dd.end());

	for(auto &&di: dd){
		cout<<get<0>(di)<<" "<<get<1>(di)<<" "<<get<2>(di)<<" "<<get<3>(di)<<" "<<get<4>(di)<<endl;
	}
	
  return 0;
}
