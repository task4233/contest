// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 063 Varied b.cpp
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

static const int MOD = 1000000007;

int main()
{
  bool check[28];
  bool ok = true;
  memset(check, false, sizeof(check));
  string inputStr;
  cin >> inputStr;
  REP(n, inputStr.size()) {
    if (check[(int)inputStr[n] - 97]) {
      ok = false;
    }
    check[(int)inputStr[n] - 97] = true;
  }
  cout << (ok ? "yes" : "no") << endl;
  return 0;
}

