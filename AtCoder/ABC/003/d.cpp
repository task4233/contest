// ------------------------------------
// Date:2018/ 2/14
// Problem:ABC 003 AtCoder社の冬 d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

#define mod 1000000007

using ll = long long;

// --------------------------------------------------
// R:部屋の行数 / C:部屋の列数
// X:壁に囲まれた区画の行数 / Y:壁に囲まれた区画の列数
// D:デスクの数　/ L:サーバラックの数


vector<vector<int>> C(1000,vector<int>(1000, -1));
int factrial[901];
int inverse[901];
long long nCr(int n,int r)
{
  return factrial[n]*(inverse[r]%mod)*(inverse[n-r]%mod);
}

int mul(int a,int b)
{
  return ((a%mod)*(b%mod))%mod;
}

long long power(int x,int y)
{
  ll ans = 1;
  while(y > 0) {
    if ((y&1) == 1) {
      ans = (ans*x)%mod;
    }
    x = (x*x)%mod;
    y >>= 0;
  }
}

void solve(const int R,const int C,const int X,const int Y,const int D,const int L)
{
  factrial[0] = 1;
  inverse[0] = 1;
  REP(i,X*Y) {
    factrial[i] = (factrial[i-1]*i)%mod;
    inverse[i] = power(factrial[i],mod-2)%mod;
  }
  
  ll regionNum,comboNum,gap;
    
  regionNum = ((R-X+1)*(C-Y+1))%mod;
  comboNum  = nCr(D+L,D)%mod;
  gap = 1;
  /*
  
  if (X*Y != D+L) {
      gap  = nCr(X*Y,D+L);
      gap -= 2*(((nCr((X-1)*Y,D+L)%mod) + (nCr(X*(Y-1),D+L)%mod))%mod);
      gap += (4*(nCr((X-1)*(Y-1),D+L)%mod) + nCr(X*(Y-2),D+L)%mod + nCr((X-2)*Y,D+L)%mod);
      gap -= 2*((nCr((X-2)*(Y-1),D+L))%mod + (nCr((X-1)*(Y-2),D+L))%mod);
      gap += nCr((X-2)*(Y-2),D+L)%mod;
  }
   */
  cout << mul(regionNum,mul(gap,comboNum)) << endl;
}
// 出力は10^9 + 7で割ったあまりを出力する。
// --------------------------------------------------

int main()
{
    int R,C,X,Y,D,L;
    cin >> R >> C >> X >> Y >> D >> L;
    solve(R,C,X,Y,D,L);
    return 0;
}

