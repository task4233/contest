#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

const int INF = 1e8 + 1;
const int MAX_N = 1e5 + 1;

// data[H][W], S:Stairs(0), E:Elevater(1)
int H, W, S, E;
double V;
int dist[2] = {-1, 1};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> S >> E >> V;
  vector< ll > tableS(W);
  vector< ll > tableE(W);
  vector< bool > ts(W, false);
  vector< bool > te(W, false);
  
  queue< int > qs;
  REP(i, S) {
    int tmpS;
    cin >> tmpS; tmpS--;
    qs.push(tmpS);
    tableS[tmpS] = 0ll;
    ts[tmpS] = true;
  }

  while(!qs.empty()) {
    int from = qs.front(); qs.pop();
    
    REP(i, 2) {
      int next = from + dist[i];
      if (!(0 <= next && next < W)) continue;
      if (ts[next]) continue;
      ts[next] = true;
      tableS[next] = tableS[from] + 1ll;
      qs.push(next);
    }
  }
  queue< int > qe;

  REP(i, E) {
    int tmpE;
    cin >> tmpE; tmpE--;
    qe.push(tmpE);
    tableE[tmpE] = 0ll;
    te[tmpE] = true;
  }
  
  while(!qe.empty()) {
    int from = qe.front(); qe.pop();
    
    REP(i, 2) {
      int next = from + dist[i];
      if (!(0 <= next && next < W)) continue;
      if (te[next]) continue;
      te[next] = true;
      tableE[next] = tableE[from] + 1ll;
      qe.push(next);
    }
  }

  /*
  REP(i, W) {
    printf("tableS[%d]:%d\n", i, tableS[i]);
  }

  REP(i, W) {
    printf("tableE[%d]:%d\n", i, tableE[i]);
  }
  */
  

  int Q;
  cin >> Q;

  while(Q--) {
    ll fromH, fromW, toH, toW;
    cin >> fromH >> fromW >> toH >> toW;
    fromH--; fromW--; toH--; toW--;
    ll tmpS = abs(fromH - toH) + tableS[fromW] + tableS[toW];
    ll tmpE = (ceil((double)abs(fromH - toH) / V)) + tableE[fromW] + tableE[toW];
    ll ans = min(tmpS, tmpE);
    // debug(tmpS);
    // debug(tmpE);
    cout << ans << endl;
  }

  return 0;
}

