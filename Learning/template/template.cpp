// ------------------------------------
// Date:2018/ 3/17
// Problem:template sample / template.cpp
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
#define debug(x) cerr << #x << ":" << x << endl;

typedef long long ll;

void CINT() {
  // 再帰の最後用に何もしない関数を用意する
}
// 1個以上のパラメータを受け取り、可変因数を先頭(Head)とそれ以外(Tail)に分解
template <class Head,class... Tail>
void CINT(Head&& head, Tail&&... tail)
{
  cin >> head;
  // 改めて引数を先頭(Head)とそれ以外(Tail)に分解するために1つ後ろにずらす
  CINT(move(tail)...);
}
// 宣言およびcin
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  // M,N: int
  CIN(M, N);
  cout << M << endl;
  cout << N << endl;
  
  // LM, LN: long long
  LCIN(LM, LN);
  cout << LM << endl;
  cout << LN << endl;

  // SM, SN: string
  SCIN(SM, SN);
  cout << SM << endl;
  cout << SN << endl;

  vector< int > v(MAX_N);
  cout << sizeof(M) << endl;
  cout << sizeof(LN) << endl;
  cout << sizeof(SN) << endl;
  
  return 0;
}

