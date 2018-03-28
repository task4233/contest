// ------------------------------------
// Date:2018/ 3/24
// Problem:C- Palindromic Matrix c.cpp
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

static const int MOD = 1e9 + 7;
static const int MAX_N = 1;

string a[100];

bool solve(vector< int > d, int m, int n)
{
  // m, n
  bool state[2];
  memset(state, false, sizeof(state));
  int rowCnt = 0;
  if (m & 1) {
    rowCnt++;
    m--;
    state[0] = true;
  }
  if (n & 1) {
    rowCnt++;
    n--;
    state[1] = true;
  }

  int edge_m = m / 2;
  int edge_n = n / 2;

  REP(i, edge_m * edge_n) {
    bool ok = false;
    REP(j, 26) {
      if (d[j] >= 4) {
	d[j] -= 4;
	ok = true;
	break;
      }
    }
    if (!ok) return false;
  }

  bool ok;
  int tmp;
  switch(rowCnt) {
  case 1:
    if (state[0]) tmp = n;
    else tmp = m;
    REP(h, n / 2) {
      ok = false;
      REP(i, 26) {
	if (d[i] > 1) {
	  d[i] -= 2;
	  ok = true;
	  break;
	}
      }
      if (!ok) return false;
    }
    break;
  case 2:
    REP(h, min(1, m >> 1) * min(n >> 1, 1)) {
      ok = false;
      REP(i, 26) {
	if (d[i] > 1) {
	  debug(d[i]);
	  d[i] -= 2;
	  ok = true;
	  break;
	}
      }
      if (!ok) return false;
    }
    break;
  }
  return true;
}

int main()
{
  int m, n;
  cin >> m >> n;
  REP(i, m) {
    cin >> a[i];
  }
  
  vector< int > d(26, 0);
  REP(hi, m) {
    REP(wi, n) {
      d[a[hi][wi] - 97]++;
    }
  }

  REP(i, 26) {
    debug(d[i]);
  }
  
  bool ok = solve(d, m, n);

  OK(ok);
  
  return 0;
}

