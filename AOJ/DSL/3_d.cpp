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

template< class Abel > class RMQ {
public:
  RMQ(int _n) {
    init(_n);
  }

  void init(int _n) {
    N = 1;
    while (N < _n) {
      // 頂点数を2のべき乗にする
      N <<= 1;
    }
    d.resize(2 * N - 1);
    for (int i = 0; i < 2 * N - 1; ++i) {
      d[i] = INF;
    }
  }

  void update(int k, Abel a) {
    // kの位置を葉まで移動
    k += N - 1;
    d[k] = a;
    // 頂点まで値を更新する
    while (k > 0) {
      k = (k - 1) / 2;
      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
    }
  }

  // 呼び出しは[a, b)の!!!半開区間!!!
  Abel _query(int _a, int _b) {
    return query(_a, _b, 0, 0, N);
  }
  
  
private:
  int N;
  vector< Abel > d;

  // 呼び出しでミスをする可能性があるので、privateにしておく
  Abel query(int a, int b, int k, int l, int r) {
    // [a, b)に対して、[l, r)が範囲として成立していない
    if (!(a < r && l < b)) return INF;
    
    // [a, b)が[l, r)を完全にカバーしている(queryを再帰的に呼び出しても範囲は狭まるだけ)
    if (a <= l && r <= b) return d[k];
    
    // それ以外の時、葉の2つの子の最小値を再帰的に求める
    Abel vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    Abel vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
  
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N, L);
  RMQ< int > rmq(N + 1);

  // vector< int > a(N);
  REP(i, N) {
    CIN(a);
    rmq.update(i, a); 
  }

  REP(lb, N - L + 1) {
    cout << rmq._query(lb, lb + L);
    if (lb == N - L) cout << endl;
    else cout << " ";
  }
  
  return 0;
}

