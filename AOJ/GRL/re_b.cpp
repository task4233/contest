#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX_V 10000
#define INF 1000000001
typedef pair<int,int> P;
 
struct edge { int to,cap,cost,rev; };
 
int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
 
void init_edge(){
  for(int i=0;i<V;i++)G[i].clear();
}
 
void add_edge(int from,int to,int cap,int cost){
  G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
  G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
 
int min_cost_flow(int s,int t,int f){
  int res = 0;
  fill(h,h+V,0);
  while(f>0){
 
    priority_queue< P, vector<P>, greater<P> >  que;
    fill( dist, dist+V , INF );
    dist[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      int v = p.second;
      if(dist[v]<p.first)continue;
      for(int i=0;i<(int)G[v].size();i++){
        edge &e = G[v][i];
        if(e.cap>0&&dist[e.to] > dist[v]+e.cost+h[v]-h[e.to]){
          dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
	  prevv[e.to] = v;
	  cout << "v:" << v << endl;
	  preve[e.to] = i;
	  cout << "i:" << i << endl;
          que.push(P(dist[e.to],e.to));
        }
      }
    }
 
    if(dist[t]==INF){
      return -1;
    }
    for(int v=0;v<V;v++)h[v]+=dist[v];

    cout << "f:" << f << endl;
    int d=f;
    for(int v=t;v!=s;v=prevv[v]){
      d=min(d,G[prevv[v]][preve[v]].cap);
      cout << G[prevv[v]][preve[v]].cap << endl;
      cout << prevv[v] << endl;
      cout << "d:" <<  d << endl;
    }
    f-=d;
    cout << "f:" << f << endl;
    res+=d*h[t];
    for(int v=t;v!=s;v=prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
    cout << "d:" << d << endl;
    cout << 1 << endl;
  }
  return res;
}
 
int main(){
  int E,F,a,b,c,d;
  cin>>V>>E>>F;
  while(E--){
    cin>>a>>b>>c>>d;
    add_edge(a,b,c,d);
  }
  cout<<min_cost_flow(0,V-1,F)<<endl;
  return 0;
}
