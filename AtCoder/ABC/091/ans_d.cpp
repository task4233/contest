// ------------------------------------
// Date:2018/ 3/18
// Problem:. . . ans_d.cpp
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
#define debug(x) cerr << #x << ":" << x << "\n";
#define OK(ok) cout << (ok ? "Yes" : "No") <<　"\n";
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
static const int MAX_N = 2e5;

int A[MAX_N];
int B[MAX_N];

int N;

int tmpA[MAX_N];

int check(int d)
{
  int mask = 1 << d;
  REP(i, N) {
    tmpA[i] = A[i] % (mask * 2);
  }

  vector< int > tmpB[2];

  REP(i, N) {
    int b = B[i] % (mask * 2);

    if (b & mask) tmpB[1].emplace_back(b - mask);
    else tmpB[0].emplace_back(b);
  }
  REP(i, N) {
    sort()
  }
    
}

int main()
{
  
  return 0;
}

