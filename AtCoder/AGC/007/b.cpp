// ------------------------------------
// Date:2018/ 3/21
// Problem:B- Construct Sequence b.cpp
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

static const int INF = 1e9 + 1;
static const int MAX_N = 1;

int main()
{
  CIN(N);
  vector< int > p(N);
  REP(i, N) {
    cin >> p[i];
  }
  vector< int > a(N + 2, -1);
  vector< int > b(N + 2, -1);
  vector< int > sum(N + 2, -1);
  FOR(i, 1, N + 1) {
    b[i] = N - i + 1;
  }

  // N < 2e4
  REP(i, N) {
    int num = p[i];
    if (i == 0) {
      a[num] = 5e5;
      sum[num] = a[num] + b[num];
    } else {
      int f, e;
      f = a[p[i - 1]] - 1000;
      e = a[p[i - 1]] + 1000;
      RFOR(j, 1, num + 1) {
	if (a[j] == -1) continue;
	else {
	  f = min(f, a[j]);
	}
      }
      FOR(j, num, N + 2) {
	if (a[j] == -1) continue;
	else {
	  e = max(e, a[j]);
	}
      }
      
      RFOR(j, f, e) {
	a[num] = j;
	if (a[num - 1] != -1) {
	  if (not(a[num] > a[num - 1] )) continue;
	  if (not(a[num] + b[num] > a[num - 1] + b[num - 1])) continue;
	}
	if (a[num + 1] != -1) {
	  if (not(a[num] < a[num + 1])) continue;
	  if (not(a[num] + b[num] < a[num + 1] + b[num + 1])) continue;
	}
	break;
      }
    }
  }
  FOR(i, 1, N + 1) {
    cout << a[i];
    cout << (i != N ? " ": "\n");
  }
  FOR(i, 1, N + 1) {
    cout << b[i];
    cout << (i != N ? " ": "\n");
  }

  return 0;
}

