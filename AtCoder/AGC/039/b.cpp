#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) std::cerr<<#x<<":"<<(x)<<std::endl;
#define INIT ios::sync_with_stdio(false);cin.tie(0);
int gcd(int a,int b){return b?gcd(b,a%b):a;}

struct UnionFind {
  vector< int > par;
  UnionFind(int n = 1) {
    init(n);
  }

  void init(int n = 1) {
    par.resize(n);
    for(int i = 0; i < n; i++)
      par[i] = -1;
  }
  
  int root(int n) {
    if (par[n] < 0) return n;
    return par[n] = root(par[n]);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;

    return true;
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x){
	  return -(par[root(x)]);
  }
};

vector<int> e[202];
vector<int> vnum(202, -10);

signed main() {
  INIT;
  int n;cin>>n;
  vector<string> s(n);
  int fr=-1;
  for(int i=0;i<n;++i) {
    cin>>s[i];
    int one = 0;
    for(int j=0;j<n;++j){
      if(s[i][j] == '1'){
        e[i].emplace_back(j);
        e[j].emplace_back(i);
        ++one;
      }
    }
    if (one==1){
      fr = i;
    }
  }

  if(fr<0) {
    cout<<-1<<endl;
    return 0;
  }

  vector<bool> visit(n, false);
  queue<int> q;
  q.push(fr);
  vnum[fr] = 0;
  
  while(!q.empty()){
    int ff = q.front();q.pop();
    if(visit[ff]) continue;
    visit[ff] = true;
    int fnum = vnum[ff];
    
    for(int i=0;i<e[ff].size();++i){
      int to = e[ff][i];
      bool ok = true;
      for(int j=0;j<e[to].size();++j){
        if(e[to][j]==ff) continue;
        ok &= (vnum[e[to][j]]==-10);
      }
      if (ok) {
        if(vnum[to]!=-10 && vnum[to]!=fnum + 1) continue;
        vnum[to] = fnum + 1;
        q.push(to);
        continue;
      }
    }
  }

  vector<int> un;
  for(int i=0;i<n;++i) if(vnum[i]==-10) un.emplace_back(i);

  auto check = [=](int frm){
                 bool res = true;
                 for(int j=0;j<e[frm].size();++j){
                   res &= abs(vnum[e[frm][j]] - vnum[frm]) == 1;
                 }
                 return res;
               };
  
  for(int i=0;i<un.size();++i){
    int ff = un[i];
    vnum[ff] = vnum[e[ff].front()] + 1;
    if(check(ff)) continue;
    vnum[ff] = vnum[e[ff].front()] - 1;
    if(check(ff)) continue;
    cout<<-1<<endl;
    return 0;
  }
  
  map<int,int> mp;
  for(int i=0;i<n;++i){
    mp[vnum[i]]++;
  }
  int ans = 0;

  /*
   for(int i=0;i<n;++i){
     debug(i);
      debug(vnum[i]);
   }
  */

  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      if(s[i][j] == '1' && vnum[i] == vnum[j]) {
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  
  for(auto&& mi:mp){
    if(mi.second>0) ++ans;
  }
  
  cout<<ans<<endl;
  
  return 0;
}
