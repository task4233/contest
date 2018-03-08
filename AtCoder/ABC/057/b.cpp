// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 057 Checkpoints b.cpp
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

typedef long long ll;

static const int MOD = 1000000007;

int N, M;

int main()
{
  cin >> N >> M;
  vector< int > a(N);
  vector< int > b(N);
  vector< int > c(M);
  vector< int > d(M);
  REP(i, N) {
    cin >> a[i] >> b[i];
  }
  REP(i, M) {
    cin >> c[i] >> d[i];
  }
  
  int num;
  ll distance, tmp;
  REP(i, N) {
    distance = 1e9;
    REP(j, M) {
      tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (tmp < distance) {
        distance = tmp;
        num = j + 1;
      }
    }
    cout << num << endl;
  }
  return 0;
}

