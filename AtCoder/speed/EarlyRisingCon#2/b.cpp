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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x = 0;
  int y = 0;
  SCIN(S);

  bool n, w, s, e;
  n = w = s = e = false;
  EACH(si, S) {
    switch(si) {
    case 'N':
      n = true;
      break;
    case 'W':
      w = true;
      break;
    case 'S':
      s = true;
      break;
    case 'E':
      e = true;
      break;
    }
  }

  if (!w && !e) {
    OK(n && s);
  } else if (!n &&  !s) {
    OK(w && e);
  } else {
    OK((n && s) && (w && e));
  }
  
  return 0;
}

