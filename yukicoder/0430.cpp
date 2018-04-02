// ------------------------------------
// Date:2018/ 4/ 2
// Problem:No.430 文字列検索 / 0430.cpp
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
typedef unsigned long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

string S;
int M;

int contain(string a, string b)
{
  if (a.size() >  b.size()) return 0;
  int res = 0;
  ll t = 1ll;
  REP(i, a.size())
    t *= MOD;

  ll hashA = 0ll, hashB = 0ll;
  REP(i, a.size())
    hashA = hashA * MOD + a[i];

  REP(i, a.size())
    hashB = hashB * MOD + b[i];

  for (int i = 0; i + a.size() <= b.size(); ++i) {
    if (hashA == hashB) res++;
    if (i + a.size() < b.size()) hashB = hashB * MOD + b[i + a.size()] - b[i] * t;
  }

  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> S;
  cin >> M;
  vector< string > C(M);
  REP(i, M)
    cin >> C[i];

  int ans = 0;
  REP(i, M)
    ans += contain(C[i], S);

  cout << ans << endl;
  
  return 0;
}

