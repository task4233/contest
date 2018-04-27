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
const int MAX_N = 1e6 + 1;

int N;
// timeTable[2t(s)][3]
double timeTable[MAX_N][3];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  vector< double > t(N);
  vector< double > v(N);

  REP(i, N) {
    cin >> t[i];
  }
  REP(i, N)
    cin >> v[i];
  
  REP(i, 2 * N) {
    timeTable[i + 1][0] = timeTable[i][0] + 0.5;
    timeTable[i + 1][1] = timeTable[i][1];
    timeTable[i + 1][2] = timeTable[i][2] - 0.5;
    
  }
  
  
  
  
  

  return 0;
}

