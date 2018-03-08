// ------------------------------------
// Date:2018/ 3/ 8
// Problem:CodeThanksFestival(Parallel) '17 Factory c.cpp
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
typedef pair< ll, ll > P;
// static const int MOD = 1000000007;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  // firstが同じ時、secondをキーとして昇順ソート
  // それ以外はfirstをキーとして昇順ソート
  priority_queue< P , vector< P >, greater< P > > q;

  ll a, b;
  REP(i, N) {
    cin >> a >> b;
    q.push(make_pair(a, b));
  }

  // O(KlogN)
  ll ans = 0ll;
  REP(i, K) {
    tie(a, b) = q.top();
    q.pop();
    // debug(a);
    // debug(b);
    ans += a;
    // debug(ans);
    q.push(make_pair(a + b, b));
  }
  cout << ans << endl;
  
  return 0;
}

