// ------------------------------------
// Date:2018/ 2/27
// Problem:ABC 079 TrainTicket c.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

using ll = long long;

#define MOD 1000000007

int main()
{
  int A, B, C, D;
  string inputStr;
  cin >> inputStr;
  A = inputStr[0] - '0';
  B = inputStr[1] - '0';
  C = inputStr[2] - '0';
  D = inputStr[3] - '0';
  
  int sum1,sum2;
  sum1 = sum2 = 0;
  REP(op1, 2) {
    if (op1 == 0) sum1 = A + B;
    else          sum1 = A - B;
      REP(op2, 2) {
        if (op2 == 0) sum2 = sum1 + C;
        else          sum2 = sum1 - C;
      
        // op3 == '+'
        if (sum2  == 7 - D) {
          cout << A << (op1==0?"+":"-") << B << (op2==0?"+":"-") << C << "+" << D << "=7" << endl;
          return 0;
        }
        // op3 == '-'
        if (sum2  == 7 + D) {
          cout << A << (op1==0?"+":"-") << B << (op2==0?"+":"-") << C << "-" << D << "=7" << endl;
          return 0;
        }
      }
  }
  return 0;
}

