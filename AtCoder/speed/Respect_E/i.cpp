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

string s, t;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s >> t;

  string ans = "";
  int num;
  bool check = false;
  REP(i, s.size()) {
    
    bool ok = true;
    REP(j, t.size()) {
      if (s[i + j] != t[j] && s[i + 1] != '?') {
	ok = false;
	// check = true;
      }
    }
    if (!ok) continue;

    num = i;
    check = true;
    if (check) break;
  }

  REP(i, t.size()) {
    s[i + num] = t[i];
  }

  REP(i, s.size()) {
    if (s[i] == '?') {
      s[i] = 'a';
    }
  }
  
  if (!check) {
    cout << "UNRESTORABLE" << endl;
  } else {
    cout << ans << endl;
  }
  

  return 0;
}

