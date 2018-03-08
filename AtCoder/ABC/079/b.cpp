// ------------------------------------
// Date:2018/ 2/27
// Problem:ABC 079 LucasNumber b.cpp
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

ll memo[100];

ll Luca(int i)
{
  if (i == 0) return 2;
  if (i == 1) return 1;
  if (memo[i] != -1) return memo[i];
  return memo[i] = Luca(i - 1) + Luca(i - 2);
}

int main()
{
  int N;
  memset(memo, -1, sizeof(memo));
  cin >> N;
  cout << Luca(N) << endl;
  return 0;
}

