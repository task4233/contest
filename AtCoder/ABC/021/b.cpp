// ------------------------------------
// Date:2018/ 3/25
// Problem:_ _ _ b.cpp
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
#define OK(ok) cout << (ok ? "YES" : "NO") << endl;
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
static const int MAX_N = 1e3 + 1;

int N, a, b, K;

bool cnt[MAX_N];

bool check(vector< int > t)
{
  memset(cnt, false, sizeof(cnt));
  cnt[a] = cnt[b] = true;
  REP(i, t.size()) {
    if (cnt[t[i]]) return false;
    cnt[t[i]] = true;
  }
  return true;
}

int main()
{
  cin >> N >> a >> b >> K;
  vector< int > t(K);
  REP(i, K) {
    cin >> t[i];
  }

  bool ok = check(t);
  OK(ok);
  
  return 0;
}

