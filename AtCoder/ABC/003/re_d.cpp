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


vector<vector<int>> memo(1000, vector<int>(1000,-1));

long long mul(long long a,long long b)
{
  return ((a%mod)*(b%mod))%mod;
}

int nCr(int n,int r)
{
  if (n<0 || r<0 || n < r) return 0;
  if (r == 0 || r == n) return 1;
  if (memo.at(n).at(r) != -1) return memo.at(n).at(r);
  return (memo.at(n).at(r) = (nCr(n-1,r-1) + nCr(n-1,r))%mod);
}

int main()
{
  int R,C,X,Y,D,L;
  cin >> R >> C >> X >> Y >> D >> L;
  const int N = D+L;
    
  ll regionNum,comboNum,gap;
    
  regionNum = ((R-X+1)*(C-Y+1));
  comboNum  = nCr(N,L);
  gap = 1;

  if (X*Y != D+L) {
    gap  = nCr(X*Y,N);
    gap %= mod;
    gap -= mul(2,(nCr((X-1)*Y,N)+nCr(X*(Y-1),N)));
    gap %= mod;
    gap += (mul(4,nCr((X-1)*(Y-1),N)) + (nCr(X*(Y-2),N) + nCr((X-2)*Y,N))%mod)%mod;
    gap %= mod;
    gap -= mul(2,(nCr((X-2)*(Y-1),N) + nCr((X-1)*(Y-2),N)))%mod;
    gap %= mod;
    gap += nCr((X-2)*(Y-2),N);
  }
  while(gap<0) gap += mod;
  cout << mul(mul(regionNum,gap),comboNum) << endl;
  
  // 出力は10^9 + 7で割ったあまりを出力する。
  // --------------------------------------------------
  return 0;
}

