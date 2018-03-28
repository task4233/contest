// ------------------------------------
// Date:2018/ 1/26
// Problem:SRM494 Div2 Level1 InterestingParty.cpp
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

class InterestingParty {
public:
  int bestInvitation(vector<string> first,
		     vector<string> second)
  {
    // --------------------------------
    // Nomal Answer
    // --------------------------------
    /*
    int fCnt,sCnt,cnt,size;
    cnt = 0;
    size = first.size();
    REP(i,size) {
      fCnt = sCnt = 0;
      REP(j,size) {
	// check first[i]
	if (first[i]==first[j])++fCnt;
	if (first[i]==second[j])++fCnt;
	// check second[i]
	if (second[i]==first[j])++sCnt;
	if (second[i]==second[j])++sCnt;
      }
      cnt = max(cnt,max(fCnt,sCnt));
    }
    */

    // --------------------------------
    // Smart Answer
    // --------------------------------

    map<string> dic;
    REP(i,first.size()) {
      dic[first[i]] = 0;
      dic[second[i]] = 0;
    }
    REP(i,first.size()) {
      ++dic[first[i]];
      ++dic[second[i]];
    }
    int ans;
    ans = 0;
    map<string,int>::iterator it;
    FOR(i,dic.begin(),dic.end()) {
      if (ans < if->second) ans = it->second;
    }
    return cnt;
  }
};

int main()
{
  InterestingParty i;
  string s1, s2;
  vector<string> first, second;
  while(cin >> s1 >> s2) {
    if (s1 == "0") break;
    first.push_back(s1);
    second.push_back(s2);
  }
  cout << "Returns:" << i.bestInvitation(first,second) << endl;
  return 0;
}

