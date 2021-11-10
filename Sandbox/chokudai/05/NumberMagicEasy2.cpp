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
    string c[] = {
      "YYYY",
      "YYYN",
      "YYNY",
      "YYNN",
      "YNYY",
      "YNYN",
      "YNNY",
      "YNNN",
      "NYYY",
      "NYYN",
      "NYNY",
      "NYNN",
      "NNYY",
      "NNYN",
      "NNNY",
      "NNNN"
    };
    REP(i,16) {
      if (answer == c[i]) return i+1;
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

