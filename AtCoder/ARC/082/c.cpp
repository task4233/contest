// ------------------------------------
// Date:2018/ 3/ 8
// Problem:ARC 082 Together c.cpp
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

static const int INF = 1000000001;

int A[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(A, 0, sizeof(A));
  int N, tmp, mMax = -INF;
  cin >> N;
  REP(i, N) {
    cin >> tmp;
    ++A[tmp];
  }

  int cnt;
  REP(i, 101001) {
    cnt = max(cnt, A[i] + A[i + 1] + A[i + 2]);
  }
  cout << cnt << endl;
  
  return 0;
}

