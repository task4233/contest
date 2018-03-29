// ------------------------------------
// Date:2018/ 3/29
// Problem:_ _ _ c.cpp
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

int N, x;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> x;

  if (x == 1 or x == 2 * N - 1) {
    cout << "No" << endl;
  } else {
    if (x > 2) {
      cout << "Yes" << endl;
      deque< int > d;
      d.push_front(x);
      d.push_front(x - 1);
      d.push_back(x + 1);
      d.push_back(x - 2);
      FOR(i, 1, x - 2) {
	if(i & 1) d.push_front(i);
	else d.push_back(i);
      }
      int bias = ((x - 4) % 2 + 2) % 2;
      FOR(i, x + 2, 2 * N) {
	if ((x + bias + i) % 2 == 1) {
	  d.push_front(i);
	} else {
	  d.push_back(i);
	}
      }
      while(!d.empty()) {
      cout << d.back() << endl;
      d.pop_back();
      }
    } else {
      if (x != N) {
	cout << "No" << endl;
      } else {
	cout << "Yes" << endl;
	FOR(i, 1, 2 * N) {
	  cout << i << endl;
	}
      }
    }
  }

  return 0;
}

