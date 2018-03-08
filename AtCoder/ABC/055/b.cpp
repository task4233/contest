// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 055 TrainingCamp b.cpp
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

long int memo[101010];

int main()
{
  int N;
  cin >> N;
  // power = 1;
  memo[0] = 1;
  FOR(i, 1, N + 1) {
    memo[i] = (memo[i - 1] * i) % MOD;
  }
  cout << memo[N] << endl;
  
  return 0;
}

