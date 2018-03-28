// ------------------------------------
// Date:2018/ 3/17
// Problem:theater kfda_ _ e.cpp
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
#define debug(x) cerr << #x << ":" << x << endl

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
static const int MAX_N = 1010101;

int t[MAX_N];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fill_n(t, MAX_N, 0);
  CIN(N);
  REP(i, N) {
    CIN(a, b);
    t[a - 1]++;
    t[b]--;
  }
  REP(i, MAX_N) {
    t[i + 1] += t[i];
  }
  int cnt = 0;
  REP(i, MAX_N) {
    if (t[i] > 0) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

