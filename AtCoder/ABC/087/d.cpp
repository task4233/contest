#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int N, M;

struct Edge {
  Edge(int _to, int _cost)
    : to(_to), cost(_cost) {}

  int to;
  int cost;
};

int d[MAX_N];

vector< Edge > e[MAX_N];

int main()
{
  cin >> N >> M;
  vector< int > l(M), r(M), d(M);
  REP(i, M) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--; r[i]--;

    e[l[i]].emplace_back(Edge(r[i], d[i]));
    e[r[i]].emplace_back(Edge(l[i], -d[i]));
  }

  REP(i, N) {
    
  }
  

  
  return 0;
}
