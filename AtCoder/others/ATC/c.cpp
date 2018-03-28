// ------------------------------------
// Date:2018/ 3/12
// Problem:ATC 001 高速フーリエ変換 c.cpp
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
typedef complex< double > CD;

static const double PI = 4.0 * atan(1.0);
static const CD I(0, 1);
static const int MOD = 1000000007;

vector< CD > fft(vector< CD > f, int N, int inverse)
{
  
}

int main()
{
  int N;
  scanf("%d", &N);
  // n次
  vector< int > a(N);
  // n次
  vector< int > b(N);
  REP(i, N) {
    cin >> a[i] >> b[i];
  }

  int powerN = 1;
  while(not(powerN > N + N)) {
    // n > deg(a) + deg(b)となるような2のべき乗を求める
    powerN <<= 1;
  }
  debug(powerN);

  vector< CD< double > > g(powerN);
  vector< CD< double > > h(powerN);
  REP(i, powerN) {
    if (i < N) {
      g[i] = a[i];
      h[i] = b[i];
    } else {
      g[i] = 0;
      h[i] = 0;
    }
  }

  g = fft(g, powerN, 1);
  h = fft(h, powerN, 1);
  
  return 0;
}

