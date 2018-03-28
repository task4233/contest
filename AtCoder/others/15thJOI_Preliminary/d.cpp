// ------------------------------------
// Date:2018/ 3/20
// Problem:Walking in JOIKingdom d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

struct data {
  int num;
  ll x;
  int dist;
};

int main()
{
  LCIN(N, T, Q);
  vector< data > d(N);
  REP(i, N) {
    cin >> d[i].x >> d[i].dist;
    d[i].num = i;
  }
  vector< int > q(Q);
  REP(i, Q) {
    cin >> q[i];
  }
  sort(ALL(d), [](data x, data y) {
      return x.x < y.x;
  });

  REP(i, N) {
    
  }
  
  return 0;
}

