#include <bits/stdc++.h>
using namespace std;

int dx[8]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};

int main() {
	int h, w;
	cin >> h >> w;
	vector< string > s(h);
	for(int hi=0;hi<h;++hi)
		cin >> s[hi];
	
	vector<string> ans(s);
	bool ok = true;
	for(int hi=0;hi<h;++hi){
		for(int wi=0;wi<w;++wi){
			if (s[hi][wi] != '#') continue;
			bool ok2 = false, ok3 = true;
			for (int di=0;di<8;++di){
				int ny = hi+dy[di], nx = wi+dx[di];
				if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
				if (di%2 == 0 && s[ny][nx] == '#') ok2 |= true;
				ok3 &= s[ny][nx] == '#';
			}
			ok &= ok2;
			ans[hi][wi] = ok3?'#':'.';
		}
	}

	vector< string > debug(ans);
	for(int hi=0; hi<h; ++hi){
		for(int wi=0; wi<w; ++wi){
			if (ans[hi][wi] != '#') continue;
			for (int di=0;di<8;++di){
				int ny = hi+dy[di], nx = wi+dx[di];
				if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
				debug[ny][nx] = '#';
			}
		}
	}
	for(int hi=0; hi<h; ++hi){
		for(int wi=0; wi<w; ++wi){
			ok &= (s[hi][wi] == debug[hi][wi]);
		}
	}
	
	if (ok){
		cout << "possible" << endl;
		for(int hi=0;hi<h;++hi){
			cout << ans[hi] << endl;
		}
	} else {
		cout << "impossible" << endl;
	}
	
  return 0;
}
