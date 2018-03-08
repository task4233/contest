// ------------------------------------
// Date:2018/ 2/13
// Problem:0005 : GCD&LCM 5.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

// PrimeNumは2以上の範囲で使用できる。
#define MaxPrimeNum 100000000
bool PrimeNum[MaxPrimeNum];

// -----------------------------------------------
void Eratosthenes()
{
  REP(i,MaxPrimeNum) PrimeNum[i] = true;
  FOR(i,2,sqrt(MaxPrimeNum)) if(PrimeNum[i]) for (int j=0;i*(j+2)<MaxPrimeNum;++j) PrimeNum[i*(j+2)] = false;
}

int Factoring(int a)
{
  return 
}
// -----------------------------------------------

int main()
{
  int a,b,lcm;
  Eratosthenes();
  lcm = lcm(a,b);
  return 0;
}

