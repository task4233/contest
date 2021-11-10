#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)

class usefulFunc{
public:
  void countStrings(vector<string> s)
  {
    map<string,int> m;
    REP(i,s.size()) {
	++m[s[i]];
    }
    map<string,int>::iterator it = m.begin();
    while(it != m.end()) {
      cout << (*it).first << " " << (*it).second << endl;
      ++it;
    }
  }
private:
};

int main()
{
  usefulFunc u;
  vector<string> vs;
  string s;
  while(s!="0") {
    cin >> s;
    vs.push_back(s);
  }
  s.pop_back();
  u.countStrings(vs);
  return 0;
}
