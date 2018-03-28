// ------------------------------------
// Date:2018/ 3/24
// Problem:Construct Sequences _ re_b.cpp
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

int main()
{
  CIN(N);
  vector< int > p(N);
  REP(i, N) cin >> p[i];
  vector< int > a(N);
  vector< int > b(N);
  REP(i, N) {
    a[i] = N * (i + 1);
    b[i] = N * (N - i);
  }

  REP(i, N) {
    a[p[i] - 1] += i;
    debug(a[p[i]]);
  }

  REP(i, N) {
    cout << a[i] << (i < N - 1 ? " " : "\n"); 
  }

  REP(i, N) {
    cout << b[i] << (i < N - 1 ? " " : "\n"); 
  }

  return 0;
}

