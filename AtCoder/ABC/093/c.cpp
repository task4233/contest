// ------------------------------------
// Date:2018/ 4/ 7
// Problem:/ / / c.cpp
//
// ------------------------------------

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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector< int > d(3);
  int even, odd;
  even = odd = 0;
  int evenMax, oddMax;
  evenMax = oddMax = 0;
  REP(i, 3) {
    cin >> d[i];
    if (d[i] & 1) {
      odd++;
      oddMax = max(oddMax, d[i]);
    }else {
      even++;
      evenMax = max(evenMax, d[i]);
    }
  }

  sort(ALL(d));

  int tmp;
  ll ans = 0ll;
  if (odd == 0 or even == 0) {
    while(1) {
      if (d[0] == d[1] && d[0] == d[2]) break;
      ans++;
      d[0] += 2;
      sort(ALL(d));
    }
  } else {
    if (odd == 1) {
      RREP(i, 3) {
	if (d[i] & 1) {
	  tmp = i;
	  break;
	}
      }
      // oddをevenのmax+1にしてからのこりを揃える
      while(d[tmp] < evenMax) {
	ans++;
	d[tmp] += 2;
      }
      sort(ALL(d));
      while(1) {
	if (d[0] == d[1]) break;
	ans++;
	d[0] += 2;
	sort(ALL(d));
      }
      ans += d[2] - d[1];
    } else {
      RREP(i, 3) {
	if (!(d[i] & 1)) {
	  tmp = i;
	  break;
	}
      }
      // oddをevenのmax+1にしてからのこりを揃える
      while(d[tmp] < oddMax) {
	ans++;
	d[tmp] += 2;
      }
      sort(ALL(d));
      while(1) {
	if (d[0] == d[1]) break;
	ans++;
	d[0] += 2;
	sort(ALL(d));
      }
      ans += d[2] - d[1];
    }
  }

  cout << ans << endl;
  
  return 0;
}

