// ------------------------------------
// Date:2018/ 2/17
// Problem:for MOD . MOD.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define MOD 1000000007

int getPow(int x,int n)
{
  ans = 1;
  while(n>0) {
    if((n&1)==1) ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}

int add(int a,int b)
{
  return (a+b)%MOD;
}

int sub(int a,int b)
{
  return (a+MOD-b)%MOD;
}

int mul(int a,int b)
{
  return ((a%MOD)*(b%MOD))%MOD;
}

int power(int x,int y)
{
  int t;
  if      (y == 0) return 0;
  else if (y == 1) return x % MOD;
  t = power(x,y/2);
  if (y%2 == 0) return (t*t)%MOD;
  else return (t*t*x)%MOD;
}

int divi(int a,int b)
{
  return mul(a,power(b,MOD-2));
}

long long getPow(long x,int n)
{
  long long ans = 1;
  while(n>0) {
    if ((n&1)==1) {
      ans *= x;
    }
    x *= x;
    n >>= 1;
  }
  return ans;
}


int main()
{
  int a = (1e9)+6;
  int b = (1e9)+5;
  cout << add(a,b) << endl;
  cout << a+b << endl << endl;
  cout << sub(a,b) << endl;
  cout << a-b << endl << endl;
  cout << mul(a,b) << endl;
  cout << a*b << endl << endl;
  cout << divi(a,b) << endl;
  cout << a/b << endl << endl;
  return 0;
}

