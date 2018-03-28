// ------------------------------------
// Date:2018/ 3/23
// Problem:Trained? _ _ b.cpp
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
static const int MAX_N = 1e5 + 1;

bool btn[MAX_N];
int N;

int main()
{
  scanf("%d", &N);
  vector< int > a(N);
  REP(i, N) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  memset(btn, false, sizeof(btn));
  btn[0] = true;
  int last = 0;
  REP(i, N) {
    if (btn[last]) {
      // debug(last);
      btn[last] = false;
      last = a[last] - 1;
      btn[last] = true;
      ans++;
      if (last == 1) break;
    } else {
      ans = -1;
      break;
    }
    if (i == N - 1) ans = -1;
  }
  cout << ans << endl;
 
  return 0;
}

