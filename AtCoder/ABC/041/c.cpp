// ------------------------------------
// Date:2018/ 2/27
// Problem:ABC 041 背の順 c.cpp
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
  int N, num;
  cin >> N;
  vector< pair< int, int > > a(N, {0, 0});
  REP(i, N) {
    cin >> num;
    a[i].first = num;
    a[i].second = i+1;
  }
  sort(ALL(a),
       [](const pair< int, int >& x, const pair< int, int >& y) {
    return x.first > y.first;
  });
  
  REP(i, N) {
    cout << a[i].second << endl;
  }
  return 0;
}

