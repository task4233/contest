// ------------------------------------
// Date:2018/ 2/14
// Problem:ABC003 d 1000000007 1000000007.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

#define ll long long
#define mod 1000000007

ll add (ll a,ll b)
{
  return (a + b) % mod;
}

ll sub(ll a,ll b)
{
  return (a + mod - b) % mod;
}

ll mul(ll a,ll b)
{
  return ((a % mod) * (b % mod)) % mod;
}

ll power(ll a,ll b)
{
  if (b == 0) {
    return 1;
  } else if (y == 1) {
    return x % mod;
  } else if (y % 2 == 0) {
    return power(x, y/2)
}

ll div(ll a,ll b)
{
  return mul(a, power(b, mod-2));
}

int main()
{
  return 0;
}

