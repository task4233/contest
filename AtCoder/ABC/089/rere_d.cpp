#include <bits/stdc++.h>
using namespace std;

// 2k*2kのマス目を考える
int sm[2020][2020];

int main() {
	int n,k;cin>>n>>k;
	vector<tuple<int,int,char>> dat(n);
	for(int i=0;i<n;++i){
		int x,y;char c;cin>>x>>y>>c;
		x %= 2*k;
		y %= 2*k;
		dat[i] = make_tuple(x,y,c);
	}

	vector<pair<int,int>> d(n);
	for(int i=0;i<n;++i){
		int x,y,c;
		tie(x,y,c)=dat[i];
		if(c=='B'){
			(x+=k)%=2*k;
		}
		d[i] = make_pair(x,y);
		//cerr<<x<<" "<<y<<endl;
	}

	for(int i=0;i<n;++i){
		int x,y;
		tie(x,y) = d[i];
		sm[y][x]++;
	}


	// 横を先にかぞえあげる
	// --->
	// --->
	// --->
	// たてを次にかぞえあげる
	// | | |
	// | | |
	// | | |
	// v v v

	for(int yi=0;yi<2*k;++yi){
		for(int xi=0;xi<2*k;++xi){
			if(xi>0)       sm[yi][xi] += sm[yi][xi-1];
			if(yi>0)       sm[yi][xi] += sm[yi-1][xi];
			if(xi>0&&yi>0) sm[yi][xi] -= sm[yi-1][xi-1];
			//cerr<<sm[yi][xi]<<" ";
		}
		//cerr<<endl;
	}

	auto getAns = [&](int x1,int y1,int x2,int y2){
		if(x1>x2 || y1>y2) return 0;
		int res = sm[y2][x2];
		if(y1>0)         res -= sm[y1-1][x2];
		if(x1>0)         res -= sm[y2][x1-1];
		if(y1>0 && x1>0) res += sm[y1-1][x1-1];
		return res;
	};

	// (0,0)      (xi,0)    (xi+k,0)        (2*k,0)
	//       ok          ng           ok
	// (0,yi)     (xi,yi)   (xi+k,yi)       (2*k,yi)
	//       ng          ok           ng
	// (0,yi+k)   (xi,yi+k) (xi+k,yi+k)     (2*k,yi+k)
	//       ok          ng           ok
	// (0,2*k-1)  (xi,2*k-1)  (xi+k,2*k-1)  (2*k,2*k-1)
	
	int ans = 0;
	for(int yi=0;yi<=k;++yi){
		for(int xi=0;xi<=k;++xi){
			int res = 0;
			res += getAns(0   ,0   ,xi-1  ,yi-1);
			res += getAns(xi+k,0   ,2*k-1 ,yi-1);
		 	res += getAns(xi  ,yi  ,xi+k-1,yi+k-1);
			res += getAns(0   ,yi+k,xi-1  ,2*k-1);
			res += getAns(xi+k,yi+k,2*k-1 ,2*k-1);
			ans = max(ans, res);
		  //cerr<<res<<endl;
			// 白黒逆の時も考える
			ans = max(ans, n-res);
			//cerr<<(n-res)<<endl;
		}
	}
	cout<<ans<<endl;
	
  return 0;
}
