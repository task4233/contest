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

const ll LINF = 1e16 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  vector< ll > memoA(N + 1, 0ll);
  // ll aSum = 0ll;
  priority_queue< ll, vector< ll >, greater< ll > > a;
  REP(i, N) {
    LCIN(t);
    // aSum += t;
    memoA[0] += t;
    a.push(t);
  }

  vector< ll > b(N);
  REP(i, N) {
    cin >> b[i];
  }

  vector< ll > memoC(N + 1, 0ll);
  // ll cSum = 0ll;
  priority_queue< ll > c;
  REP(i, N) {
    LCIN(t);
    // cSum += t;
    memoC[0] += t;
    c.push(t);
  }

  REP(i, N) {
    a.push(b[i]);
    memoA[i + 1] = memoA[i] - a.top(); a.pop();
    memoA[i + 1] += b[i];

    c.push(b[N - i - 1]);
    memoC[i + 1] = memoC[i] - c.top(); c.pop();
    memoC[i + 1] += b[N - i - 1];
  }

  ll ans = -LINF;
  REP(i, N + 1) {
    // debug(memoA[i + 1]);
    // debug(memoC[N - i + 1]);
    ll tmp = memoA[i] - memoC[N - i];
    // debug(tmp);
    ans = max(ans, tmp);
  }

  cout << ans << endl;

  /*
  REP(i, N + 1) 
    debug(memoA[i]);

  cout << endl;
  
  REP(i, N + 1)
    debug(memoC[i]);
  */

  return 0;
}

