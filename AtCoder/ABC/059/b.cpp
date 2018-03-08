// ------------------------------------
// Date:2018/ 3/ 1
// Problem:ABC 059 Comparison b.cpp
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
  string A, B;
  string ans;
  cin >> A >> B;
  if (A.size() > B.size()) {
    ans = "GREATER";
  } else if (A.size() < B.size()) {
    ans = "LESS";
  } else {
    if (A == B) ans = "EQUAL";
    else if (A > B) ans = "GREATER";
    else ans = "LESS";
  }
  cout << ans << endl;
  return 0;
}

