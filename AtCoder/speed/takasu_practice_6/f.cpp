// ------------------------------------
// Date:2018/ 3/26
// Problem:B - 謎のたこ焼きおじさん f.cpp
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

int N, M;
string name;
string kit;

int nameCnt[26];
int kitCnt[26];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  cin >> name;
  cin >> kit;

  REP(ni, name.size())
    nameCnt[name[ni] - 65]++;
  REP(ki, kit.size())
    kitCnt[kit[ki] - 65]++;

  int ans = 0;
  REP(i, 26) {
    if (kitCnt[i] < 1) {
      if (nameCnt[i] > 0) {
	cout << -1 << endl;
	return 0;
      }
      continue;
    }
    
    ans = max((nameCnt[i] + kitCnt[i] - 1) / kitCnt[i], ans);
    // printf("%c\n", i + 65);
    // debug(ans);
  }

  cout << ans << endl;
  
  return 0;
}

