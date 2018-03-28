// ------------------------------------
// Date:2018/ 3/13
// Problem:ABC 069 4-Adjacent c.cpp
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

  int N;
  cin >> N;
  int a, four, two, other;
  four = two = other = 0;
  REP(i, N) {
    cin >> a;
    if (a % 4 == 0) four++;
    else if (a % 2 == 0) two++;
    else other++;
  }

  bool ok = true;
  if (two > 0) {
    if (other > four) ok = false;
  } else {
    if (other - 1 > four) ok = false;
  }

  cout << (ok ? "Yes" : "No") << endl;
  
  return 0;
}

