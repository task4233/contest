
// ------------------------------------
// Date:2018/ 2/20
// Problem:SRM484 Div2 Level1 NumberMagicEasy.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

class NumberMagicEasy {
private:
  char check(int x[], int number)
  {
    REP(i,8) {
      if(x[i] == number) return 'Y';
    }
    return 'N';
  }
public:
  int theNumber(string answer)
  {
    int A[] = {1, 2, 3, 4, 5,  6,  7,  8};
    int B[] = {1, 2, 3, 4, 9, 10, 11, 12};
    int C[] = {1, 2, 5, 6, 9, 10, 13, 14};
    int D[] = {1, 3, 5, 7, 9, 11, 13, 15};
    FOR(i,1,17) {
      if (check(A,i) != answer[0]) continue;
      if (check(B,i) != answer[1]) continue;
      if (check(C,i) != answer[2]) continue;
      if (check(D,i) != answer[3]) continue;
      return i;
    }
    return 0;
  }
};

int main()
{
  NumberMagicEasy n;
  string answer;
  cin >> answer;
  cout << n.theNumber(answer) << endl;
  return 0;
}

