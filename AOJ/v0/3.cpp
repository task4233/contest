// ------------------------------------
// Date:2018/ 2/12
// Problem:0003 : IsItRightTriangle 3.cpp
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

int main()
{
  int N;
  vector<int> d(3,0);
  cin >> N;
  while(N--) {
    scanf("%d %d %d",&d[0], &d[1], &d[2]); 
    sort(d.begin(),d.end(), std::greater<int>());
    if (d.at(0)*d.at(0)==d.at(1)*d.at(1)+d.at(2)*d.at(2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}

