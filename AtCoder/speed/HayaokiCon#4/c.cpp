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

int N;

vector< int > e[MAX_N];
// Fenec:0 / Snuke:1
int state[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N - 1) {
    CIN(a, b);
    a--; b--;
    e[a].emplace_back(b);
    e[b].emplace_back(a);
  }

  memset(state, -1, sizeof(state));
  
  state[0] = 0;
  state[N - 1] = 1;

  set< int > a;
  EACH(i, e[0]) {
    a.insert(i);
  }
  set< int > b;
  EACH(i, e[N - 1]) {
    b.insert(i);
  }

  REP(i, N) {
    cout << i << endl;
    if (i & 2) {
      // Snuke
      bool ok = false;
      EACH(bi, b) {
	if (a.find(bi) != a.end()) {
	  // 見つけた
	  a.erase(bi);
	  b.erase(bi);
	  state[bi] = 1;
	  ok = true;
	}
	if (ok) break;
      }
      if (!ok) {
	if (b.size() == 0) {
	  cout << "Fenec" << endl;
	  return 0;   
	}
	auto tmp = b.begin();
	state[*tmp] = 1;
	a.erase(b.begin());
      }
    } else {
      // Fenec
      bool ok = false;
      EACH(ai, a) {
	if (b.find(ai) != b.end()) {
	  // 見つけた
	  a.erase(ai);
	  b.erase(ai);
	  state[ai] = 0;
	  ok = true;
	}
	if (ok) break;
      }
      if (!ok) {
	if (a.size() == 0) {
	  cout << "Snuke" << endl;
	  return 0;   
	}
	auto tmp = a.begin();
	state[*tmp] = 0;
	a.erase(a.begin());
      }
    }
    if (a.size() == 0 or b.size() == 0) {
      break;
    }
  }
  if (N & 2) {
    cout << "Snuke" << endl;
  } else {
    cout << "Fenec" << endl;
  }

  return 0;
}

