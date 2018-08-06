#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

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
const int MAX_N = 575;

int T;
ll A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

/*
bool solve(ll tmp, int i)
{
  ll divisor = D[i] % B[i];
  // debug(divisor);
  ll j = -tmp;
  ll res = j;
  // debug(j);
  if (divisor == 0) {
    return true;
  } else {
    if (j >= C[i]) res = j;
    else {
      res = j;
      while(res <= C[i]) {
	res += max((C[i] - res) / divisor, 1ll) * divisor ;
      }
    }
    //if (res <= C[i]);
  }
  // debug(res);
  return !(res < B[i]);  
}
*/

bool solve2(ll tmp, int i, set< ll > s)
{
  if (D[i] % B[i] == 0) return true;
  if (tmp >= C[i]) {
    tmp = (tmp + D[i]) % B[i];
    if (s.erase(tmp)) return true;
    s.insert(tmp);
    return solve2(tmp, i, s);
  } else return false;
}

int main()
{

  cin >> T;
  REP(i, T) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  REP(i, T) {

    
    if (A[i] < B[i]) {
      OK(false);
      continue;
    }
    
    // cout << A[i] << "," <<  B[i] << ","  << C[i] << "," << D[i] << endl;
    
    if (B[i] > D[i]) {
      OK(false);
      continue;
    }

    ll tmp = (A[i] - C[i]) % B[i] + C[i];// + C[i] - B[i];
    if (tmp > C[i] + B[i]) {
      OK(false);
      continue;
    }
    // debug(tmp);
    set< ll > s;
    s.insert(tmp);
    OK(solve2(tmp - B[i], i, s));
  }

  return 0;
}

