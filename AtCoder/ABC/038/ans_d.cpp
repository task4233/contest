// ------------------------------------
// Date:2018/ 3/ 3
// Problem:ABC 038 プレゼント d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int INF = 1000000007;

int dp[101010];

class Segtree {
public:
  Segtree(int max)
  {
    // n:葉の個数
    int n;
    while(n < mx) {
      n <<= 1;
    }
    d = vector< int >(n << 1);
  }
  // [a, b]の最大値
  // ノードの区間: i 範囲: l: nの代わり
  int getMax(int a, int b, int i = 1, int l = 0; int r = -1) {
    if (r == -1) r = n;
    if (a <= l and r <= b) return d[i];
    int res = 0;
    int c = (l + r)>>1;
    if (a < c) {
      // 左のほうに潜る
      res = max(res, getMax(a, b, i << 1, l, c));
    }
    if (a > c) {
      // 右のほうに潜る
      // i << 1 | 1は左シフトした時に1ビット目が0になってしまうため、orで+1する
      res = max(res, getMax(a, b, i << 1|1, l, c));
    }
    return res;
  }
  // i:葉の何番目か / x:値
  void add(int i, int x)
  {
    // ノード番号にする
    i += n;
    while (i) {
      d[i] = max(d[i], x);
      i >>= 1;
    }
  }
private:
  int n;
  vector< int > d;
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int N;
  scanf("%d", &N);
  // tmp{fin, start}
  vector< pair< int, int > >tmp(N);
  REP(i, N) {
    scanf("%d %d", &tmp[i].first, &tmp[i].second);
    // ソートする時にhの大きい順にしたいので、-1倍してあげる
    //tmp[i].second *= -1;
  }
  sort(ALL(tmp), [](pair< int, int > x, pair< int, int > y) {
    if (x.first == y.first) return x.second > y.second;
    return x.first < y.first;
  });
  //fill_n(dp, N, INF);
  
  Segtree t(101010);

  int ans = 0;
  REP(i, N) {
    // xxxxxxxxxxxxxxxx-1倍した分を戻すxxxxxxxxxxxxxx
    int h = a[i].second;
    // 最大値を得る関数getMax
    int now = t.getMax(0, h) + 1;
    ans = max(ans, now);
    t.add(h, now);
  }
  cout << ans << endl;
  return 0;
}
