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

ll n, d[2 * MAX_N - 1];

void init(ll _n) {
  n = 1;
  while (n < _n) {
    // nを2のべき乗にする
    n <<= 1;
  }

  REP(i, 2 * n - 1) {
    // 全ての値をINFで初期化
    d[i] = INF;
  }
}

// k番目の値(0-indexed)をaに変更
void update(ll k, ll a) {
  // k番目の値 = (葉よりも上の数 + k)なので
  k += n - 1;
  d[k] = a;
  // 登りながら更新
  while (k > 0) {
    // あとで　試す
    k = (k - 1) / 2;
    d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);
  }
}

// [a, b)の最小値を求める
// 後ろの方の引数は計算を簡単にするための引数
// kは節点の番号, l, rはその節点が[l, r)に対応していることを示す
// したがって外からはquery(a, b, 0, 0, n)として呼ぶ
ll query(ll a, ll b, ll k, ll l, ll r) {
  /*
  debug(a);
  debug(b);
  debug(k);
  debug(l);
  debug(r);
  */
  // [a, b)と[l, r)が交差しなければINF
  if (r <= a || b <= l) return INF;
  // cout << "flag1" << endl;

  // [a, b)が[l, r)を完全に含んでいればこの節点の値
  if (a == l && r == b) return d[k];
  // cout << "flag2" << endl;
  
  // そうでなければ2つの子の最小値
  ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
  ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
  return min(vl, vr);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, Q);
  init(N + 1);

  REP(qi, Q) {
    LCIN(c, x, y);
    if (c == 0) {
      // update
      update(x, y);
    } else {
      // find
      cout << query(x, y + 1, 0, 0, n) << endl;
    }
  }

  /*
  REP(i, n * 2 - 1) {
    debug(i);
    debug(d[i]);
  }
  */

  return 0;
}

