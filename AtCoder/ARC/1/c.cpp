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

bool b[8][8];

int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};

int check(int hi, int wi, int ret) {
  int nextX;
  // 縦
  REP(i, 4) {
    
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(hi, 8) {
    REP(wi, 8) {
      char ch;
      scanf("%c", &ch);
      b[hi][wi] &= (ch == 'Q');
    }
  }

  bool ok = true;
  REP(hi, 8) {
    REP(wi, 8) {
      if (c[hi][wi]) {
	int ret = check(hi, wi, 0);
	ok &= (ret > 1);
	if (ret == 0) {
	  c[hi][wi] = true;
	}
      }
    }
  }

  if (!ok) {
    cout << "No Answer" << endl;
    return 0;
  }

  REP(hi, 8) {
    REP(wi, 8) {
      cout << c[hi][wi] ? "Q" : ".";
    }
    cout << endl;
  }
  
  return 0;
}

