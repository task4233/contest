// ------------------------------------
// Date:2018/ 3/20
// Problem:A- SelectingSubjects _ a.cpp
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
#define OK(ok) cout << (ok ? "Yes" : "No") <<　endl;
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

int main()
{
  vector< int > science(4);
  vector< int > social(2);
  REP(i, 4) {
    scanf("%d", &science[i]);
  }
  REP(j, 2) {
    scanf("%d", &social[j]);
  }
  sort(ALL(science), greater< int >());

  int ans = 0;
  REP(i, 3) {
    ans += science[i];
  }
  ans += max(social[0], social[1]);

  cout << ans << endl;
  return 0;
}

