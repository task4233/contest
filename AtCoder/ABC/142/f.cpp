#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);

int n,m;
vector<int> e[1010], ev[1010];
bool canVisit[1010][1010];

void bfs(int fr){
  queue<int> q;
  for(int i=0;i<e[fr].size();++i){
    int to = e[fr][i];
    canVisit[fr][to] = true;
    q.push(to);
  }

  while(!q.empty()) {
    int frm = q.front();q.pop();
    for(int i=0;i<e[frm].size();++i){
      int to = e[frm][i];
      if(canVisit[fr][to]) continue;
      canVisit[fr][to] = true;
      q.push(to);
    }
  }
}

int restore(int p, int q, int dg){
  sort(e[p].begin(), e[p].end());
  if(!binary_search(e[p].begin(), e[p].end(), q)) {
    swap(p,q);
  }

  sort(e[p].begin(), e[p].end());
  if(!binary_search(e[p].begin(), e[p].end(), q)) {
    return 0;
  }

  vector<int> ans;
  vector<int> dist(n,1e9+1);
  queue<int> qq;
  qq.push(q);
  dist[q] = 0;

  while(!qq.empty()) {
    int fr = qq.front(); qq.pop();
    if (fr == p) break;
    
    for(int i=0;i<e[fr].size();++i){
      int to = e[fr][i];
      if(dist[to] <= dist[fr] + 1) continue;
      dist[to] = dist[fr] + 1;
      qq.push(to);
    }
  }
  
  int st = p;
  ans.emplace_back(st);
  //debug(st);
  //// debug(dist[st]);
  if (dg==1) {
    return dist[st];
  }
  for(int i=0;i<n;++i){
    for(int j=0;j<ev[st].size();++j){
      int to = ev[st][j];
      if (dist[to] == dist[st] - 1) {
        st = to;
        ans.emplace_back(to);
        break;
      }
    }
  }
  
  
  reverse(ans.begin(), ans.end());
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();++i){
    cout<<ans[i]+1<<endl;
  }
  
  return 1;
}

signed main() {
  INIT;
  cin>>n>>m;
  for(int i=0;i<m;++i){
    int p,q;cin>>p>>q;
    --p;--q;
    e[p].emplace_back(q);
    ev[q].emplace_back(p);
  }

  memset(canVisit, false, sizeof(canVisit));

  for(int i=0;i<n;++i) bfs(i); 

  int mn = 1e9+1, idf=-1, idt= -1;
  for(int i=0;i<n-1;++i){
    for(int j=i+1;j<n;++j){
      if(canVisit[i][j] && canVisit[j][i]) {
        int tmp = restore(i,j,1);
        if(tmp==0) continue;
        if(tmp<mn){
          // debug(tmp);
          mn = tmp;
          idf = i;idt = j;
        }
      }
    }
  }
  if(idf>=0 && idt>=0) {
    // debug(idf);
    // debug(idt);
    restore(idf,idt,0);
  }
  else {
  
  cout<<-1<<endl;
  }
  return 0;
}
