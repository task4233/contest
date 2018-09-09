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
  BIT(int _n) : N(_n) { init(); }

  void init() {
    // [1, N]の範囲なので、+1する必要がある
    bit.clear();
    bit.resize(N + 1, 0);
  }

  void add(int i, Abel x) {
    while (i <= N) {
      bit[i] += x;
      i += i & -i;
    }
  }

  Abel sum(int i) {
    Abel sm = 0;
    while (i > 0) {
      sm += bit[i];
      i -= i & -i;
    }
    return sm;
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

  CIN(N, M, Q);
  vector< BIT< int > > bit(N + 1, BIT< int >(N + 1));

  REP(i, M) {
    CIN(L, R);
    REP(j, L + 1) {
      bit[j].add(R, 1);
    }
  }

  REP(qi, Q) {
    CIN(p, q);
    cout << bit[p].sum(q) << endl;
  }
  
  return 0;
}

