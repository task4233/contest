// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 081 PlacingMarbles a.cpp
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
  cin.tie(0);
  ios::sync_with_stdio(false);


  string S;
  cin >> S;
  int cnt = 0;
  REP(i, S.size()) {
    if (S[i] == '1') ++cnt;
  }
  printf("%d\n", cnt);
  
  return 0;
}

