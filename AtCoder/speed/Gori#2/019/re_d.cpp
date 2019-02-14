#include <bits/stdc++.h>
using namespace std;

int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main() {
	int h,w;
	cin >> h >> w;
	vector< string > s(h);
	for(int hi=0;hi<h;++hi) cin >> s[hi];

	vector< string > ans(s);
	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			if (s[hi][wi] != '.') continue;
			for (int di=0;di<8;++di){
				int ny = hi+dy[di], nx = wi+dx[di];
				if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
				ans[ny][nx] = '.';
			}
		}
	}

	vector< string > debug(ans);
	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			if (ans[hi][wi] != '#') continue;
			
			
			for (int di=0;di<8;++di){
				int ny = hi+dy[di], nx = wi+dx[di];
				if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
				debug[ny][nx] = '#';
			}
		}
		cerr << ans[hi] << "\n";
	}

	bool ok = true;
	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			ok &= s[hi][wi] == debug[hi][wi];
		}
		cerr << s[hi] << "\n";
	}

	for(int hi=0;hi<h;++hi){
		cerr << debug[hi] << "\n";
	}

	
	

	if (ok) {
		cout << "possible" << endl;
		for(int hi=0;hi<h;++hi){
			cout << ans[hi] << endl;
		}
	} else {
		cout << "impossible" << endl;
	}
  return 0;
}
