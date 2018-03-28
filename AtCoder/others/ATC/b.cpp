// ------------------------------------
// Date:2018/ 3/10
// Problem:ATC 001 UnionFind b.cpp
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

static const int MOD = 1000000007;

static const int MAX_N = 1e5;

// par: parents of Union-Find tree
int par[MAX_N];
// int rank[MAX_N];

// 初期化
void init(int n)
{
  REP(i, n) {
    // par[i]が負の数の時、その頂点自身が(属性)根である
    par[i] = -1;
  }
}

// root(x): xが所属するグループの属性(根)を返す
int root(int x)
{
  if (par[x] < 0) {
    // par[x]が負の時、定義よりその頂点自身が属性(根)である
    return x;
  } else {
    // not( par[x] < 0 )の時、その頂点自身が親玉ではないため、その親の属性を再帰的に探る
    return root(par[x]);
  }
}

bool same(int x, int y)
{
  // 根が同じ集合に属するか否かを返す
  return root(x) == root(y);
}

bool unite(int x, int y)
{
  // xとyの根が異なる時、yにxを併合する.
  // その際、大きい方に小さい方が併合されるようにpar[x]とpar[y]の大小関係を比較する
  
  x = root(x);
  y = root(y);
  if (x == y) {
    // すでにxとyの根が同じ時は併合する必要はない
    return false;
  }
  if (par[x] > par[y]) {
    // xの方を小さくしておく
    swap(x, y);
  }
  par[x] += par[y];
  par[y] = x;
  return true;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;

  init(N);
  REP(i, Q) {
    int p, a, b;
    cin >> p >> a >> b;
    if (p == 0) {
      // 連結する
      unite(a, b);
    } else {
      // 判定する
      if (same(a, b)) {
	cout << "Yes" << endl;
      } else {
	cout << "No" << endl;
      }
    }
  }
  return 0;
}

