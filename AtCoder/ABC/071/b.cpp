// ------------------------------------
// Date:2018/ 3/12
// Problem:ABC 071 NotFound b.cpp
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

bool state[26];

int main()
{

  memset(state, true, sizeof(state));
  string S;
  cin >> S;
  REP(i, S.size()) {
    state[S[i] - 97] = false;
  }

  REP(i, 26) {
    if (state[i]) {
      printf("%c\n", i + 97);
      return 0;
    }
  }
  printf("None\n");
  return 0;
}

