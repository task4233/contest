#include <bits/stdc++.h>
using namespace std;
using int64 = int64_t;
#define int int64

int nt[2020][2020];
int st[2020][2020];
int wt[2020][2020];
int et[2020][2020];

signed main() {
	int h,w;cin>>h>>w;
	vector<string> s(h);
	for(int i=0;i<h;++i) cin>>s[i];

	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			if(s[hi][wi] == '#') continue;
			if(hi-1>=0 && s[hi-1][wi] == '.') nt[hi][wi] = nt[hi-1][wi] + 1;
			if(wi-1>=0 && s[hi][wi-1] == '.') wt[hi][wi] = wt[hi][wi-1] + 1;
		}
	}

	for(int hi=h-1;hi>=0;--hi){
		for(int wi=w-1;wi>=0;--wi){
			if(s[hi][wi] == '#') continue;
			if(hi+1<h && s[hi+1][wi] == '.') st[hi][wi] = st[hi+1][wi] + 1;
			if(wi+1<w && s[hi][wi+1] == '.') et[hi][wi] = et[hi][wi+1] + 1;
		}
	}
	
	auto _cnt = [&](int hi,int wi){
								int res=0;
								res  = nt[hi][wi] + st[hi][wi];
								res *= wt[hi][wi] + et[hi][wi];
								return res;
							};
	
	int ans = 0;
	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			if(s[hi][wi] == '#') continue;
			ans += _cnt(hi,wi);
		}
	}
	cout<<ans<<endl;
	
  return 0;
}

