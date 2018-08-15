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

template< class Abel > class BIT {
public:
  BIT(int _n)
    : N(_n) {
    init(_n);
  }

  void init(int _n) {
    bit.resize(_n + 1);
  }
  
  Abel sum(int i) {
    Abel s = 0;
    while (i > 0) {
      s += bit[i];
      // iの最後の1ビットを求めるときはi & -1
      i -= i & -i;
    }
    return s;
  }

  void add(int i, Abel x) {
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
  }

  Abel getSum(int _x, int _y) {
    return sum(_y) - sum(_x - 1);
  }
  
private:
  int N;
  vector< Abel > bit;
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, Q);
  BIT< ll > bit(N);

  REP(qi, Q) {
    CIN(c, _x, _y);
    if (c == 0) {
      // add
      bit.add(_x, _y);
    } else {
      // sum
      cout << bit.getSum(_x, _y) << endl;
    }
  }

  return 0;
}

