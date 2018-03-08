// ------------------------------------
// Date:2018/ 2/28
// Problem:ABC 054 OneCardPoker a.cpp
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
  int A, B;
  string output;
  cin >> A >> B;
  if (A == B) {
    output = "Draw";
  } else if (A == 1) {
    output = "Alice";
  } else if (B == 1) {
    output = "Bob";
  } else if (A > B) {
    output = "Alice";
  } else {
    output = "Bob";
  }
  cout << output << endl;
  return 0;
}

