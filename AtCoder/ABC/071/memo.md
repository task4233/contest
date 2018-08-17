# ABC071-D : Coloring Dominoes
## 問題文
https://beta.atcoder.jp/contests/arc081/tasks/arc081_b  

2 * Nのマス目があり、このマス目にN個のドミノを重ならないように敷き詰める。  
ドミノは1 * 2または2 * 1のマス目を覆うことができ、  
これらのドミノを赤、水、緑色の3色で塗る。  

ただし、辺で接しているドミノは異なる色で塗るようにする。  
また、3色全ての色を全て使う必要はない。  

このような塗り方が何通りあるかを`mod 1000000007`で求めよ。  

## 制約
 - 1 ≦ N ≦ 52
 - |S_1| = |S_2| = N
 - S_1, S_2は英小文字または英大文字からなる
 - S_1, S_2は正しいドミノの敷き詰め方を表している

## 考え方
場合分けをして考える。  
以下の画像のように場合分けができる。  
![場合分け]("./abc071_d.jpg", "場合分け")  

まず、画像の上側を説明すると、  

 - 縦に置かれたaというドミノの塗り方がK[通り]である場合  
1. 横置きのb, cというドミノがある場合  
   辺で隣接しているドミノは異なる色でなければならないから、  
   まず、bの塗り方は2[通り]である(aとは異なる色にする必要がある)。  
   次に、cの塗り方は1[通り]である(aとbと異なる色にする必要があるため)。  
   
   したがって、この時の塗り方は<u>K * 2 * 1[通り]</u>である。  
2. 縦置きのbというドミノがある場合  
   辺で隣接しているドミノは異なる色でなければならないかた、  
   bの塗り方は2[通り]である(aとは異なる色にする必要があるため)。  
   
   したがって、この時の塗り方は<u>K * 2[通り]</u>である。  

 - 横に置かれたa, bというドミノの塗り方がK[通り]である場合  
 1. 横置きのc, dというドミノがある場合  
	辺で隣接しているドミノは異なる色でなければならないから、  
	この時の並べ方は以下のように列挙できるので、  
	
	|a|c|  
	|:-:|:-:|  
	|b|a|  

	|a|b|  
	|:-:|:-:|  
	|b|a|  

	|a|b|  
	|:-:|:-:|  
	|b|c|  

	の3[通り]である。  
 2. 縦置きのcというドミノがある場合  
	辺で隣接しているドミノは異なる色でなければならないから、  
	cの塗り方は1[通り]である(aともbとも異なる色にする必要があるため)。  

以上の場合分けを元にコーディングすると以下のようになる。  

```cpp
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

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  pair< string, string > S;
  cin >> S.first >> S.second;
  // debug(S.first);
  // debug(S.second);
  
  ll ans = 1ll;
  
  int last = -1;
  // 0: 縦/ 1: 横
  int state;
  REP(i, N) {
    // debug(S.first[i]);
    // debug(S.second[i]);
    if (S.first[i] == S.second[i]) {
      // 縦
      state = 0;
    } else {
      // 横
      state = 1;
      // 横の時は2マス占領するためi++する必要がある。
      i++;
    }
    // debug(state);

    if (last == -1) {
      // 初回
      if (state == 0) {
	// 縦
	ans *= 3ll;
      } else {
	ans *= 3ll * 2ll;
      }
    } else if (last == 0) {
      // 縦
      (ans *= 2ll) %= MOD;
    } else {
      // 横
      if (state == 1) {
	// 縦
	(ans *= 3ll) %= MOD;
      }
    }
    last = state;
    // debug(last);
    // debug(ans);
  }
  cout << ans << endl;

  return 0;
}
```

