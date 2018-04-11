// ------------------------------------
// Date:2018/ 4/ 8
// Problem:/ / / a.cpp
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

int N;

int data[MAX_N];
int B[MAX_N];

int solve(int i)
{
  if (i == 0) return 0;
  int last = i;
  int target = B[i];
  {
    int mx = 0;
    int mn = INF;
    REP(i, N) {
      if (B[i] == target) {
	mx = max(mx, data[i + 1]);
	mn = min(mn, data[i + 1]);
      }
    }
  }

  data[target] = solve(target) + 1;
  
  
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N - 1) {
    cin >> B[i];
    B[i]--;
  }

  // i番目のB[i]はi + 1番目の社員の情報
  REP(i, N - 1) {
    solve(i);
  }

  int mn = INF;
  REP(i, N - 1) {
    if (B[i] == 0) {
      mn = min(mn, data[i + 1] + 1);
    }
  }
  REP(i, N) {
    debug(data[i]);
  }

  debug(mn);
  debug(data[0]);
  int ans = mn + data[0] + 1;
  cout << ans << endl;
  
  return 0;
}

