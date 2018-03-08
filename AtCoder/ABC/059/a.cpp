// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 059 Three-letterAcronym a.cpp
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
  string s1, s2, s3;
  cin >> s1 >> s2 >>s3;
  printf("%c", toupper(s1[0]));
  printf("%c", toupper(s2[0]));
  printf("%c\n", toupper(s3[0]));
  return 0;
}

