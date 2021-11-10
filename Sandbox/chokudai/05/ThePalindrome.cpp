// ------------------------------------
// Date:2018/ 1/30
// Problem:SRM428 Div2 Level1 ThePalindrome.cpp
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

class ThePalindrome {
public:
  int find(string s)
  {
    // ----------------------------
    // Answer
    // ----------------------------
    for(int i = s.size();;++i) {
      bool flag;
      REP(j,s.size()) {
	if ((i-j-1)<s.size() && s[j] != s[i-j-1]) {
	  flag = false;
	  break;
	}
      }
      if (flag) return i;
    }
    
    // -----------------------------
    // bad code
    // -----------------------------
    /*
    int size;
    bool flag;
    REP(i,s.size()) {
      if (s[s.size()-1] == s[i]) {
	s.pop_back();
	flag = true;
      }	else {
	flag = false;
      }
      cout << i << ":" << s << endl;
    }
    size = s.size()*2+1;
    if (flag) --size;
    return size;
    */
  }
};

int main()
{
  ThePalindrome p;
  string str;
  cin >> str;
  cout << p.find(str) << endl;
  return 0;
}

