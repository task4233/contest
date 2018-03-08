// ------------------------------------
// Date:2018/ 2/24
// Problem:AGC 004 DivideACuboid a.cpp
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
  int n;
  vector<int> data(3);
  REP(i,3) {
    cin >> data[i];
    if (data[i]%2 == 0) {
      cout << "0" << endl;
      return 0;
    }
  }
  sort(ALL(data));
  cout << data[0]*data[1] << endl;
  
  return 0;
}

