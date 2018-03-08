// ------------------------------------
// Date:2018/ 2/26
// Problem:ABC 051 Haiku a.cpp
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

typedef long long ll;

#define MOD 1000000007

int main()
{
  string inputStr,tmp;
  cin >> inputStr;
  tmp = inputStr.substr(0,5);
  cout << tmp << " ";
  tmp = inputStr.substr(6,7);
  cout << tmp << " ";
  tmp = inputStr.substr(14,5);
  cout << tmp << endl;
  return 0;
}

