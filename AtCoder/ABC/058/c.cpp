// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 058 怪文書 c.cpp
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

int dic[26];
int tmpDic[26];

int main()
{
  memset(dic, 1000000, sizeof(dic));
  int N;
  string inputStr;
  cin >> N;
  REP(i, N) {
    cin >> inputStr;
    memset(tmpDic, 0, sizeof(tmpDic));
    REP(j, inputStr.size()) {
      ++tmpDic[(int)inputStr[j] - 97];
    }
    REP(j, 26) {
      dic[j] = min(dic[j], tmpDic[j]);
    }
  }
  REP(i, 26) {
    REP(j, dic[i]) {
      printf("%c", 97 + i);
    }
  }
  printf("\n");
  return 0;
}

