// ------------------------------------
// Date:2018/ 2/13
// Problem:bitset sample // bitset.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main()
{
  // 8bitで131を表現
  bitset<8> b1(131);
  cout << "b1=" << b1 << endl;

  // 2bit目を1に
  b1.set(2);
  // 7bit目を0に
  b1.reset(7);

  cout << "b1=" << b1 << endl;
  // unsigned longに変換
  cout << "(unsigned long)b1=" << b1.to_ulong() << endl;

  // bit反転
  b1.flip();

  cout << "b1=" << b1 << endl;

  // 配列のようにアクセス
  cout << "b1's each bit:: ";
  REP(bit,b1.size()) {
    cout << b1[b1.size()-1-bit] << " ";
  }
  cout << endl;

  // bitがセットされているか否か
  if (1 == true) {
    cout << "b1 isAny :"  << b1.any()  << endl;
    cout << "b1 isNone :" << b1.none() << endl;
  }
  // セットされているbitの個数
  cout << "b1 count : " << b1.count() << endl;


    // bitセット同士の演算
    bitset<8> b2(5);
    cout << "b1 or  b2="  << (b1|b2) << endl;
    cout << "b1 and b2=" << (b1&b2) << endl;
    
  return 0;
}

