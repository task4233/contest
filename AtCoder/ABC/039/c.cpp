

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

string S;
string data = "WBWBWWBWBWBW";

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> S;
  int locate = 0;
  int num = -1;
  int cnt = 0;
  REP(h, data.size()) {
    if (data[h] == 'B') continue;
    locate = 0;
    cnt = 0;
    REP(j, S.size()) {
      int i = (h + j) % data.size();
      // i %= data.size();
      if (data[i] != S[locate]) {
	cnt = 0;
	locate = 0;
	break;
      }
      cnt++;
      if (cnt == data.size() - 1) {
	num = h;
	break;
      }
      locate++;
    }
    if (num > -1) break;
  }
		       
  string ans;
  switch(num) {
  case 0:
    ans = "Do";
    break;
  case 2:
    ans = "Re";
    break;
  case 4:
    ans = "Mi";
    break;
  case 5:
    ans = "Fa";
    break;
  case 7:
    ans = "So";
    break;
  case 9:
    ans = "La";
    break;
  case 11:
    ans = "Si";
    break;
  }

  cout << ans << endl;
  

  return 0;
}

// WBWBWWBWBWBWWBWBWWBW

