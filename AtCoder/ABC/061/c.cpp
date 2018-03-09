// ------------------------------------
// Date:2018/ 3/ 8
// Problem:ABC 061 BigArray c.cpp
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
typedef pair< ll, ll > M;

static const int INF = 1000000001;

//static const int MAX_DATA = 101010;
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N, K;
  cin >> N >> K;

  vector< M > data(N, make_pair(INF, INF));
  int a, b;
  REP(i, N) {
    cin >> a >> b;
    data[i] = make_pair(a, b);
  }

  sort(ALL(data));

  ll bias = 0;
  ll ans = data[0].first;
  REP(i, N) {
    ans = data[i].first;
    bias += data[i].second;
    if (bias > K - 1) break;
  }
  
  cout << ans << endl;
  
  return 0;
}

