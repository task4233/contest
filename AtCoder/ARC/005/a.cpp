// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ARC 005 大好き高橋君 a.cpp
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
  int N, cnt = 0;
  string inputStr;
  cin >> N;
  REP(i, N) {
    cin >> inputStr;
    if (inputStr == "TAKAHASHIKUN" ||
        inputStr == "Takahashikun" ||
        inputStr == "takahashikun") {
      ++cnt;
    }
    if (i == N-1) {
      if (inputStr == "TAKAHASHIKUN." ||
          inputStr == "Takahashikun." ||
          inputStr == "takahashikun.") {
        ++cnt;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
