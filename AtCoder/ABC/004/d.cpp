// ------------------------------------
// Date:2018/ 2/15
// Problem:ABC 004 マーブル d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define debug(x) cerr << #x << ": " << x << '\n';

inline int X(int n) { return n+450; }

// ---------------------------------------------------
// isContain[450] = X(0)とする
bool isContain[901];
// ---------------------------------------------------

int main()
{
  int R,G,B,tmp,t;
  cin >> R >> G >> B;
  
  int rMoveNum,gMoveNum,bMoveNum,sLimit,lLimit;
  rMoveNum = gMoveNum = bMoveNum = 0;
  REP(i,901) isContain[i] = false;
  isContain[X(-100)] = true;
  isContain[X(0)] = true;
  isContain[X(100)] = true;
  
  // RGB[1,5]の時 順番G>R=B
  // R
  t = (G-1)/2;
  /*
  REP(gi,(G-1)/2) {
    isContain[X(-1*gi)] = true;
    isContain[X(gi)] = true;
    gMoveNum += 2*(gi+1);
  }
  */
  gMoveNum += t*(t+1);
  // Limitはtrueがギリギリ含まれる値
  lLimit = (G-1)/2;
  sLimit = (-1)*lLimit;
  if (G%2==0) {
    if (R<B) {
      isContain[X(sLimit)] = true;
      --sLimit;
      gMoveNum -= sLimit;
    } else {
      isContain[X(lLimit)] = true;
      ++lLimit;
      gMoveNum += lLimit;
    }
  }
  //debug(gMoveNum)
  
  // R
  if (X(sLimit) <= X(-100)) {
    //cout << "rflag0" << endl;
    rMoveNum += (X(-100)-X(sLimit))*R;
    rMoveNum += (R-2)*(R-1)/2;
  } else {
    tmp = X(sLimit)-X(-100);
    if (tmp < (R-1)/2) {
      //cout << "rflag1" << endl;
      rMoveNum += tmp*(tmp+1)/2;
      R -= tmp+1;
      rMoveNum += R*(R-1)/2;
    } else {
      t = (R-1)/2;
      /*
      REP(ri,(R-1)/2) {
        isContain[X(-1*ri)] = true;
        isContain[X(ri)] = true;
        rMoveNum += 2*(ri+1);
      }
      */
      rMoveNum += t*(t+1);
      if (R%2==0) rMoveNum += (R+1)/2;
    }
  }
  
  //debug(rMoveNum)
  
  // B
  if (X(100) <= X(lLimit)) {
    //cout << "bflag0" << endl;
    bMoveNum += (X(lLimit)-X(100))*B;
    bMoveNum += (B-2)*(B-1)/2;
  } else {
    tmp = X(100)-X(lLimit);
    if (tmp < (B-1)/2) {
      //cout << "bflag1" << endl;
      bMoveNum += tmp*(tmp+1)/2;
      //debug(bMoveNum)
      B -= tmp+1;
      bMoveNum += B*(B-1)/2;
    } else {
      //cout << "bflag2" << endl;
      /*
      REP(bi,(B-1)/2) {
        isContain[X(-1*bi)] = true;
        isContain[X(bi)] = true;
        bMoveNum += 2*(bi+1);
      }
      */
      t = (B-1)/2;
      bMoveNum += t*(t+1);
      if (B%2==0) bMoveNum += (B+1)/2;
    }
  }

  //debug(bMoveNum)
  
  cout << rMoveNum+gMoveNum+bMoveNum << endl;
  return 0;
}

