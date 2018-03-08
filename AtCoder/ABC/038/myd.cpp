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
    // 葉の個数
    int n;
    while (n < max) {
      // 葉の位置を移動
      n <<= 1;
    }
    // 1個分多めに用意する
    d = vector< int >(n << 1);
  }


  // 区間[a,b]の最大値を求める
  // i: ノードの区間 / l: 範囲 / r: nの代わり
  int getMax(int a, int b, int i=1, int l=0, int r=-1)
  {
    if (r == -1) r = n;
    // もし区間[a,b]に値が収まっていた場合、その値を返す
    if (a <= l and r <= b) return d[i];

    int res = 0;
    // c: Segtreeの中央の値
    int c = (l + r)>>1;
    if (a < c) {
      // 真ん中の値よりも左側に位置しているため、左側に潜る
      res = max(res, getMax(a, b, i << 1, l, c));
    }
    if (a > c) {
      // 真ん中の値よりも右側に位置しているため、右側に潜る
      res = max(res, getMax(a, b, 1 << 1 | 1, l, c));
    }
    return res;
  }

  // i:今潜っている部分の葉のうち何枚目か
  // x:値
  void add(int i, int x)
  {
    i += n;
    while (i) {
      // これやっとかないとケースを落とすことがしばしばある
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

  vector< pair< int, int > > tmp(N);
  REP(i, N) {
    scanf("%d %d", &tmp[i].first, &tmp[i].second);
  }

  sort(ALL(tmp), [](pair< int, int > x, pair< int, int > y) {
	if (x.first == y.first) return x.second > y.second;
	return x.first < y.first;
  });

  Segtree t(101010);

  int ans = 0;
  REP(i, N) {
    int h = tmp[i].second;
    // 区間[0, h]の最大値を求める
    // +1は最大値の隣を見たいから
    int now = t.getMax(0, h) + 1;
    ans = max(ans, now);
    t.add(h, now);
  }
  cout << ans << endl;
  return 0;
}

