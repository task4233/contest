// ------------------------------------
// Date:2018/ 3/29
// Problem:双子とスイカ割り / / b.cpp
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

int N, A, B;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> A >> B;
  int pos = 0;
  string s;
  int d;
  REP(i, N) {
    cin >> s >> d;
    if (s == "West") {
      if (d < A)      pos -= A;
      else if (d > B) pos -= B;
      else            pos -= d;
    } else {
      if (d < A)      pos += A;
      else if (d > B) pos += B;
      else            pos += d;
    }
    debug(pos);
  }

  if (pos > 0) s = "East ";
  else if (pos < 0) s = "West ";
  else {
    cout << 0 << endl;
    return 0;
  }

  cout << s << abs(pos) << endl;
  
  return 0;
}

