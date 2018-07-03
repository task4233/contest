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
const int MAX_N = 2e5 + 1;

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  if (a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0ll;
 
  RREP(i, N - 1) {
    if (a[i + 1] - a[i] >= 2) {
      cout << -1 << endl;
      return 0;
    }
  }

  /*
  REP(i, N) {
    cout << a[i] << " ";
  }
  cout << endl;
  debug(ans);
  */

  last = a.back();
  ll cnt = 0ll;
  RREP(i, N - 1) {
    /*  
    cout << "begin" << endl;
    debug(i);
    debug(a[i]);
    debug(last);
    debug(cnt);
    debug(ans);
    cout << endl;
    */
    
    if (a[i] < last) {
      // cout << "1" << endl;)
      if (a[i] == 0) {
	ans += max(last - a[i] - 1ll, 0ll);
	ans += cnt + 1;
	cnt = 0ll;
	i--;
	last = a[i];
      } else {
	ans += max((last - a[i] - 1) / (a[i] + 1) + ((last - a[i] - 1) % (a[i] + 1)), 0ll);
	last = a[i];
	cnt++;
      }
    } else if (a[i] == last) {
      //  cout << "2" << endl;
      ans += last;
      if (cnt != 0) {
	ans += cnt + 1;
      }
      cnt = 0ll;
    } else {
      //  cout << "3" << endl;
      // 右から見て、増えてるとき
       if (last != 0) {
	 if (last == 1) {
	   ans += cnt;
	 } else {
	   ans += cnt + 1;
	 }
       }
       ans += max(last - 1, 0ll);
       cnt = 0ll;
       last = a[i];
    }
    
    /*
    cout << "end" << endl;
    debug(i);
    debug(a[i]);
    debug(last);
    debug(cnt);
    debug(ans);
    cout << endl << endl;
    */
  }

  cout << ans << endl;

  return 0;
}

