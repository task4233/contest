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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  ll p;
  vector< ll > b(N);
  ll aSum = 0ll;
  priority_queue< ll, vector< ll >, greater< ll >  > a;
  priority_queue< ll > c;
  REP(i, N) {
    cin >> p;
    a.push(p);
    aSum += p;
  }
  // sort(ALL(a));
  
  REP(i, N)
    cin >> b[i];

  ll cSum = 0ll;
  REP(i, N) {
    cin >> p;
    c.push(p);
    cSum += p;
  }
  // sort(ALL(c), greater< ll >());
  
  ll ans = -LINF;
  vector< ll > aS(N);
  vector< ll > cS(N);
  // debug(ans);
  int aMax, cMax, aCnt, cCnt;
  aMax = cMax = aCnt = 0;
  cCnt = N - 1;
  REP(i, N) {
    a.push(b[aCnt]);
    aSum += b[i] - a.top(); a.pop();
    aCnt++;

    c.push(b[cCnt]);
    cSum += b[N - i - 1] - c.top(); c.pop();
    cCnt--;

    aS[aCnt] = aSum;
    cS[cCnt] = cSum;
    // ans = max(ans, aSum - cSum);
    
    // debug(aSum);
    // debug(cSum);
    // debug(ans);
  }

  REP(i, N) {
    ans = max(ans, aS[i] - cS[N - i]);
  }
  cout << ans << endl;
   

  return 0;
}

