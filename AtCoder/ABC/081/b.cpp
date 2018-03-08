// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 081 ShiftOnly b.cpp
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  scanf("%d", &N);
  vector< int > A(N);
  REP(i, N) {
    scanf("%d", &A[i]);
  }

  bool ok = true;
  int cnt = 0;
  while (ok) {
    REP(i, N) {
      if (A[i] == 0) ok = false;
      else if (A[i] % 2 == 0) {
	A[i] /= 2;
      } else {
	ok = false;
      }
      //debug(A[i]);
    }
    ++cnt;
  }

  printf("%d\n", cnt - 1);
  
  return 0;
}

