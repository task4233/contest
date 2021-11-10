// ------------------------------------------
// Date:2018/01/25
// Problem:SRM478 Div2 Level1 kiwiJuiceEasy
//
// ------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class kiwiJuiceEasy{
public:
  vector<int> thePouring(vector<int> capacities,
			 vector<int> bottles,
			 vector<int> fromId,vector<int> toId)
  {
    REP(i,fromId.size()) {
      int f,t,space;
      f = fromId[i];
      t = toId[i];

      int vol;
      vol = min(bottles[f], capacities[t]-bottles[t]);

      bottles[f] -= vol;
      bottles[t] += vol;

      // --------------------------------
      // defencive-code
      // --------------------------------
      /*
      int sum;
      sum = bottles[f] + bottles[t];
      bottles[t] = min(capacities[t]);
      bottles[f] = sum - bottles[t];
      */

      // --------------------------------
      // da-code
      // --------------------------------
      /*
      space = cappacities[t]-bottles[t];
      if (bottles[f] <= space) {
	bottles[t] += bottles[f];
      } else {
	bottles[t] += space;
	bottles[f] -= space;
      }
      */
    }
    return bottles;
  }
};

int main()
{
  return 0;
}

