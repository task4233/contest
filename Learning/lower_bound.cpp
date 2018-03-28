// ------------------------------------
// Date:2018/ 3/14
// Problem:二分探索sample . . lower_bound.cpp
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

static const int MAX_N = 100010;

int N, K;
int A[MAX_N];

int solve(int n)
{
  int lb = -1;
  int ub = n;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (A[mid] >= K) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return ub;
}


int main()
{
  cin >> N >> K;

  int ans = solve(N);

  cout << ans << endl;
  
  return 0;
}

