// ------------------------------------
// Date:2018/ 2/16
// Problem:dp_fibo.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

bool done[100000000];
int memo[100000000];

int fib(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (done[n]) return memo[n];
  done[n] = true;
  return memo[n] = fib(n-1) + fib(n-2);
}

int main()
{
  int n;
  cin >> n;
  memset(memo, -1, sizeof(memo));
  cout << fib(n) << endl;
  return 0;
}

