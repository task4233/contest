// ------------------------------------
// Date:2018/ 1/27-29
// Problem:SRM150 Div2 Level2 InterestingDigits.cpp
//
// ------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class InterestingDigits {
public:
  vector<int> digits(int base)
  {
    vector<int> ans;
    FOR(i,2,base) {
      if (((base-1)%i)==0) ans.push_back();
    }
    /*
    FOR(n,2,base) {
      bool ok = true;
      REP(i,base) {
	REP(j,base) {
	  REP(k,base) {
	    if ((i+j*base+k*base*base) % n == 0 && (i+j+k)%n != 0) {
	      ok = false;
	      break;
	    }
	  }
	  if (!ok) break;
	}
	if (!ok) break;
      }
      if (ok) ans.push_back(n);
    }
      */
    return ans;
  }
};

int main()
{
  return 0;
}

