#include <bits/stdc++.h>
using namespace std;

int memo[2525][2525];

int main() {
	int n,m;cin>>n>>m;
	vector<string> s(n);
	for(int i=0;i<n;++i) cin>>s[i];
	
	auto _cnt = [&](int hi,int wi){
							 int cnt = 0;
							 // ne
							 if(0<=wi+1 && wi+1<m && s[hi][wi+1]=='.' &&
									0<=hi-1 && hi-1<n && s[hi-1][wi+1]=='.'){
								 for(int hj=hi-1;hj>=0;--hj){
									 if(s[hj][wi+1]=='#') break;
									 ++cnt;
									 cerr<<hj<<" "<<wi+1<<endl;
								 }
								 cerr<<cnt<<endl;
							 }
							 // nw
							 if(0<=hi-1 && hi-1<n && s[hi-1][wi]=='.' &&
									0<=wi-1 && wi-1<m && s[hi-1][wi-1]=='.'){
								 for(int wj=wi-1;wj>=0;--wj){
									 if(s[hi-1][wj]=='#') break;
									 ++cnt;
									 cerr<<hi-1<<" "<<wj<<endl;
								 }
								 cerr<<cnt<<endl;
							 }
							 // sw
							 if(0<=wi-1 && wi-1<m && s[hi][wi-1]=='.' &&
									0<=hi+1 && hi+1<n && s[hi+1][wi-1]=='.'){
								 for(int hj=hi+1;hj<n;++hj){
									 if(s[hj][wi-1]=='#') break;
									 ++cnt;
									 cerr<<hj<<" "<<wi-1<<endl;
								 }
								 cerr<<cnt<<endl;
							 }
							 // se
							 if(0<=hi+1 && hi+1<n && s[hi+1][wi]=='.' &&
									0<=wi+1 && wi+1<m && s[hi+1][wi+1]=='.'){
								 for(int wj=wi+1;wj<m;++wj){
									 if(s[hi+1][wj]=='#') break;
									 ++cnt;
									 cerr<<hi+1<<" "<<wj<<endl;
								 }
								 cerr<<cnt<<endl;
							 }
							 return cnt;
						 };

	int ans = 0;
	for(int hi=0;hi<n;++hi){
		for(int wi=0;wi<m;++wi){
			if(s[hi][wi] == '#') continue;
			ans += _cnt(hi,wi);
		}
	}
	cout<<ans<<endl;
	
  return 0;
}
