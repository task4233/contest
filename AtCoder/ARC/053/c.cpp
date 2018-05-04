
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
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

typedef pair< ll, ll > PL;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  ll a, b;
  vector< PL > dec;
  vector< PL > inc;
  REP(i, N) {
    cin >> a >> b;
    if (a > b) inc.emplace_back(make_pair(a, b));
    else dec.emplace_back(make_pair(a, b));
  }

  {
    // dec
    sort(ALL(dec),[](PL x, PL y) {
	if (x.first == y.first) return x.second > y.second;
	return x.first < y.first;
    });

    // inc
    sort(ALL(inc), [](PL x, PL y) {
	if (x.second == y.second) return x.first < y.first;
	return x.second > y.second;
    });
  }

  ll ans = 0ll;
  ll temp = 0ll;
  REP(i, dec.size()) {
    tie(a, b) = dec[i];
    temp += a;
    ans = max(ans, temp);
    temp -= b;
    // ans = max(ans, temp);
  }

  REP(i, inc.size()) {
    tie(a, b) = inc[i];
    temp += a;
    ans = max(ans, temp);
    temp -= b;
  }

  /*
  EACH(di, data) {
    debug(di.first);
    debug(di.second);
  }
  */
 
  cout << ans << endl;
  
  return 0;
}


