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

int C[3][3];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 3)
    REP(j, 3)
      cin >> C[i][j];


  bool ok = true;
  REP(i, 3) {
    int tmp = 0;
    // b2 - b1
    // tmp += C[i][1] - C[i][0];
    // b3 - b2
    // tmp += C[i][2] - C[i][1];
    REP(j, 2) {
      tmp += C[i][j + 1] - C[i][j];
    }
    if (C[i][2] - C[i][0] != tmp) ok &= false;
  }

  REP(i, 3) {
    {
      ok &= (C[1][i] - C[0][i] == C[2][i] - C[1][i]);
      ok &= (C[2][i] - C[
    }
  }

  OK(ok);
  
  return 0;
}

