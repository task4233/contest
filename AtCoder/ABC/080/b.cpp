// ------------------------------------
// Date:2018/ 3/ 6
// Problem:ABC 080 HarshadNumber b.cpp
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

int harshad(int n, int sum)
{
  if (n < 10) return n;
  return harshad(n / 10, sum + n % 10);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string N;
  cin >> N;

  int harshad = 0;
  int n = atoi(N.c_str());
  bool ok = false;
  REP(i, N.size()) {
    harshad += N[i] - '0';
  }
  
  if (n % harshad == 0) ok = true;

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}

 
