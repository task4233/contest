#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;
typedef pair< ll, ll > P;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< P > d(N + 1);
  REP(i, N) {
    CIN(a);
    d[i] = make_pair(a, i);
  }
  d[N] = make_pair(0, LINF);
  
  sort(ALL(d), [](P x, P y) {
      if (x.first == y.first) return x.second < y.second;
      return x.first > y.first;
    });

  /*
  REP(i, N) {
    debug(d[i].first);
    debug(d[i].second);
  }
  */
  
  int cnt, last;
  vector< ll > ans(N, 0ll);
  cnt = last = 0;
  ll mn = LINF;
  REP(i, N) {
    
    if (cnt == 0) {
      last = i;
      mn = min(mn, d[last].second);
    }
    // debug(last);
    
    if (d[i].first - d[i + 1].first == 0) {
      cnt++;
      // last = i;
    } else {
      ans[mn] += (d[last].first - d[i + 1].first) * (i + 1);
      cnt = 0;
    }
  }

  REP(i, N) {
    cout << ans[i] << endl;
  }
  
  return 0;
}

