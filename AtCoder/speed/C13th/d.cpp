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

int N;
int cnt[9];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  memset(cnt, 0, sizeof(cnt));
  cin >> N;
  vector< int > a(N);
  REP(i, N) {
    cin >> a[i];
    int tmp = a[i] / 400;
    if (tmp > 8) tmp = 8;
    cnt[tmp]++;
  }

  int tmp = 0;
  int mn;
  REP(i, 8) {
    if (cnt[i] > 0) tmp++;
    // debug(cnt[i]);
  }
  // debug(tmp);
  if (cnt[8] > 0) {
    if (tmp == 0) mn = 1;
    else mn = tmp;
  } else {
    mn = tmp;
  }
  // debug(mn);

  int mx = min(tmp + cnt[8], 8);


  cout << mn << " " << mx << endl;
  

  return 0;
}

