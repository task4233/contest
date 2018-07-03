#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

ll K;

int main()
{
  scanf("%lld", &K);
  FOR(i, 1, min(K, 10ll)) {
    // 10まで
    printf("%d\n", i);
  }
  if (K < 10) {
    return 0;
  } else {
    K -= 9ll;
  }
  vector< pair< double, ll > > d;
  ll sn = 1;
  ll lb = 10ll;
  ll ub;
  int cnt = 0;
  while(K > 0) {
    ub = lb * 10ll;
    FOR (i, lb, ub) {
      if (cnt == 10) {
	cnt = 0;
	sn -= 8ll;
      }
      d.emplace_back(make_pair((double)i / (double)sn, i));
      cnt++;
      sn++;
    }
    
    sort(ALL(d));
    
    REP(i, d.size()) {
      printf("%lld\n", d[i].second);
      K--;
      if (K <= 0) break;
    }
    lb *= 10ll;
    cnt = 0;
    sn = 1ll;
    d.clear();
  }
 
  
  return 0;
}

