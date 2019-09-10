#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 1e5 + 1;

vector< int > e[3][MAX_N];
int dist[3][MAX_N];

int main() {
  int n,m; cin>>n>>m;
  for(int i=0;i<m;++i){
    int u,v; cin>>u>>v;
    --u; --v;
    for(int j=0;j<3;++j){
      e[j][u].push_back(v);
    }
  }

  int s,t; cin>>s>>t;
  --s;--t;

  memset(dist, -1, sizeof(dist));

  // queue< status, node >
  queue< pair<int,int> > q;
  q.push(make_pair(0,s));
  dist[0][s] = 0;

  while(!q.empty()){
    int stat, from;
    tie(stat, from) = q.front(); q.pop();

    for(auto &&to: e[stat][from]) {
      // 更新されてたらcontinue
      if (~dist[(stat+1)%3][to]) continue;
      dist[(stat+1)%3][to] = dist[stat][from] + 1;
      q.push(make_pair((stat+1)%3,to));
    }
  }

  int ans = dist[0][t]/3;
  if (dist[0][t]<0) ans = dist[0][t];
  cout << ans << endl;
  
  return 0;
}
