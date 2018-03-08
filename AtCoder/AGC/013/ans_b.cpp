// ------------------------------------
// Date:2018/ 2/26
// Problem:AGC 013 HamiltonishPath b.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

bool G[10000][10000];

int main()
{
  int N,M;
  bool state[10001];
  cin >> N >> M;
  memset(state,false,sizeof(state));
  vector<int> a(M);
  vector<int> b(M);
  REP(i,M) {
    cin >> a[i] >> b[i];
  }
  return 0;
}

