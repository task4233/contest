// ------------------------------------
// Date:2018/ 4/14
// Problem:/ / / d.cpp
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

ll fact[MAX_N];

int N;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  fact[0] = 1ll;
  FOR(i, 1, MAX_N) {
    fact[i] = fact[i - 1] * i;
  }
  
  cin >> N;
  vector< ll > a(N);
  REP(i, N)
    cin >> a[i];

  sort(ALL(a));

  ll n = a.back();
  a.pop_back();

  ll dist = INF;
  int r = 0;
  REP(i, a.size()) {
    ll tmp = n - a[i];
    if (abs(tmp - a[i]) < dist) {
      r = a[i];
      dist = abs(tmp - a[i]);
    }
  }

  cout << n << " " << r << endl;

  return 0;
}

