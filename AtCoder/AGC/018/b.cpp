// ------------------------------------
// Date:2018/ 3/27
// Problem:B - Sports b.cpp
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
const int MAX_N = 300;

int N, M;
int A[MAX_N][MAX_N];

struct Data {
  int type;
  int num;
};

int solve(vector< int > p)
{
  int ans = N;
  int maxNum;
  int loopCnt = p.size();
  while (loopCnt--){
    
    map< int, int > m;
    
    REP(ni, N) {
      REP(mi, M) {
	if (binary_search(ALL(p), A[ni][mi])) {
	  m[A[ni][mi]]++;
	  break;
	}
      }
    }

    int tmp = 0;
    EACH(mi, m) {
      if (tmp < mi.second) {
	maxNum = mi.first;
	tmp = mi.second;
      }
    }

    REP(ni, N) {
      REP(mi, M) {
	if (A[ni][mi] == p[maxNum - 1]) A[ni][mi] = 0;
      }
    }
    
    // debug(ans);
    ans = min(ans, tmp);
  }

  return ans;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  cin >> N >> M;
  REP(hi, N)
    REP(wi, M) cin >> A[hi][wi];
  
  vector< int > p(M);
  iota(ALL(p), 1);

  int ans = solve(p);
  cout << ans << endl;

  return 0;
}

