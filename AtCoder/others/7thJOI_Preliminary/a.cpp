// ------------------------------------
// Date:2018/ 3/ 2
// Problem:JOI '07 おつり a.cpp
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
  int x, c, cnt = 0;
  scanf("%d", &x);
  c = 1000 - x;
  cnt += c/500;
  c %= 500;
  cnt += c/100;
  c %= 100;
  cnt += c/50;
  c %= 50;
  cnt += c/10;
  c %= 10;
  cnt += c/5;
  c %= 5;
  cnt += c;
  
  printf("%d\n", cnt);
  return 0;
}

