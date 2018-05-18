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

  SCIN(s);
  CIN(K);

  set< string > d;
  REP(i, s.size()) {
    REP(j, 5) {
      string tmp = s.substr(i, j + 1);
      d.erase(tmp);
      d.insert(tmp);
    }
  }

  // string ans = *(d.begin() + d.size() - K + 1);

  auto itr = d.begin();
  // cout << *(d.begin() + (auto)K - 1) << endl;

  
  REP(i, K - 1) {
    itr++;
    // debug(*itr);
  }
  
  string ans = *itr;

  
  /*
  for (auto itr = d.begin(); itr != d.end() - K + 1; ++itr) {
    ans = *itr;
  }
  */
  

  cout << ans << endl;
  

  return 0;
}


