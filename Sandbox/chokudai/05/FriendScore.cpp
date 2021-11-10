// ------------------------------------
// Date:2018/ 1/30
// Problem:SRM436 Div2 Level1 FriendScore.cpp
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

class FriendScore {
public:
  int highestScore(vector<string> friends)
  {
    int size,returns[52],ans;
    size = friends.size();
    ans = 0;
    REP(i,50) returns[i]=0;
    // 全ての頂点から開始
    FOR(i,1,size) {
      // 他の頂点に対して探索
      REP(j,i) {
	cout << friends.at(i)[j] << endl;
	if (friends.at(i)[j]=='Y') {
	  ++returns[j];
	  ++returns[i];
	  if (i < size-1 && friends.at(i+1)[j+1]=='Y') {
	    ++returns[j];
	    ++returns[j+2];
	  }
	}
      }
    }
    REP(i,size) {
      cout << i << ":" << returns[i] << endl;
      ans = max(ans,returns[i]);
    }
    return ans;
  }
};

int main()
{
  FriendScore f;
  vector<string> friends;
  string str;
  while(cin >> str) {
    if (str == ".") break;
    friends.push_back(str);
  }
  cout << f.highestScore(friends) << endl;
  return 0;
}

