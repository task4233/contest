#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

int h,w,n;
pair<int,int> s;
vector<string> t;
vector< pair<int,int> > g(9);

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int b_bfs(int num) {
  // debug(num);
  vector< vector<int> > state(h, vector<int>(w, 1e9+1));
  
  queue< pair<int,int> > q;
  q.push(make_pair(s.first, s.second));
  state[s.first][s.second] = 0;

  // debug(q.size());
  while(!q.empty()) {
    int fy,fx;
    tie(fy,fx) = q.front(); q.pop();

    // debug(fy);
    // debug(fx);
    if(fy==g[num].first && fx==g[num].second) {
      break;
    }
    // debug(fx);
    // debug(fy);
    for(int di=0;di<4;++di){
      int ny=fy+dy[di];
      int nx=fx+dx[di];

      // debug(ny);
      // debug(nx);
      if(!(0<=ny&&ny<h&&0<=nx&&nx<w)) continue;
      if(t[ny][nx] == 'X') continue;
      if(state[ny][nx] != 1e9+1) continue;

      state[ny][nx] = state[fy][fx] + 1;
      q.push(make_pair(ny,nx));
      // debug(ny);
      // debug(nx);
    }
  }
  s = make_pair(g[num].first, g[num].second);
  return state[g[num].first][g[num].second];
}

signed main() {
  cin>>h>>w>>n;
  t.resize(h);
  for(int i=0;i<h;++i) cin>>t[i];

  for(int hi=0;hi<h;++hi){
    for(int wi=0;wi<w;++wi){
      if(t[hi][wi] == 'S') s = make_pair(hi,wi);
      if('1' <= t[hi][wi] && t[hi][wi] <= '9') g[t[hi][wi]-'1'] = make_pair(hi,wi);
    }
  }

  int ans = 0;
  for(int i=0;i<n;++i){
    ans += b_bfs(i);
  }
  cout<<ans<<endl;
  
  return 0;
}
