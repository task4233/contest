#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

typedef long long ll;

const int MOD = 1000000007;
const int MAX_N = 1e5 + 1;

struct Edge {
  Edge(int _to, int _cost)
    : to(_to), cost(_cost){}
  int to;
  int cost;
};


int N, M;

vector< Edge > e[MAX_N];
vector< int > path;
int d[MAX_N];
bool state[MAX_N];


int main()
{
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  vector< int > l(M);
  vector< int > r(M);
  vector< int > D(M);
  REP(i, M) {
    cin >> l[i] >> r[i] >> D[i];
    l[i]--; r[i]--;
    e[l[i]].emplace_back(Edge(r[i], D[i]));
  }

  
  vector< int > indeg(N, 0);
  stack< int > S;

  EACH(i, e) {
    EACH(si, i) {
      indeg[si.to]++;
    }
  }

  
  REP(i, N) {
    if (indeg[i] == 0)
      S.push(i);
  }

  
  while(!S.empty()) {
    int from = S.top(); S.pop();
    path.emplace_back(from);
    EACH(to_e, e[from]) {
      indeg[to_e.to]--;
      if (indeg[to_e.to] == 0)
    	S.push(to_e.to);
    }
  }
  
  
  bool ok = (path.size() == N);

  
  if (!ok) {
    OK(ok);
    return 0;
  }


  REP(i, N) {
    if (state[path[i]]) continue;

    int start = path[i];

    stack< int > s;
    
    d[start] = 0;
    state[start] = true;

    s.push(start);
    
    while(!s.empty()) {
      int from = s.top(); s.pop();
      
      EACH(to_e, e[from]) {
	/*
	debug(from);
	debug(d[from]);
	debug(to_e.to);
	debug(to_e.cost);
	debug(d[to_e.to]);
	OK(state[to_e.to]);
	*/
	if (!state[to_e.to]) {
	  d[to_e.to] = d[from] + to_e.cost;
	  state[to_e.to] = true;
	  s.push(to_e.to);
	} else {
	  if (d[to_e.to] != d[from] + to_e.cost) {
	    ok = false;
	  }
	}
	
      }
      if (!ok) break;
    }
  }

  OK(ok);
  

  return 0;
}

