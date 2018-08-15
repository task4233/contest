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

const ll INF = (1ll << 31) - 1ll;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

template< class Abel > class RMQ {
public:
  RMQ(int _n = 1) {
    init(_n);
  }

  void init(int _n) {
    N = 1;
    while (N < _n) N <<= 1;
    d.resize(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; ++i) {
      d[i] = INF;
    }
  }

  void update(int x, Abel a) {
    x += N - 1;
    d[x] = a;
    while (x > 0) {
      x = (x - 1) / 2;
      d[x] = min(d[x * 2 + 1], d[x * 2 + 2]);
    }
  }

  // [a, b)の最小値を求める
  // 見ているのは[l, r)をカバーしている節点x
  Abel query(int a, int b, int x, int l, int r) {
    // 異常な範囲
    if (!(a < r && l < b)) return INF;
    // [l, r)∈[a, b)の時、範囲は狭まる一方なのでそこの節点の値を返す
    if (a <= l && r <= b) return d[x];

    Abel vl = query(a, b, x * 2 + 1, l, (l + r) / 2);
    Abel vr = query(a, b, x * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

  Abel _query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  
private:
  int N;
  vector< Abel > d;
  
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, Q);
  RMQ< long long int > rmq(N + 1);
  
  REP(i, Q) {
    CIN(c, _x, _y);
    if (c == 0) {
      // update
      rmq.update(_x, _y);
    } else {
      cout << rmq._query(_x, _y + 1) << endl;
    }
  }

  return 0;
}

