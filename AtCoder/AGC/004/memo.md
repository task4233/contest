# AGC004-B : Colorful Slimes
## 問題文
https://beta.atcoder.jp/contests/agc004/tasks/agc004_b
N色のスライムが存在する。  
最初は1匹もスライムを飼っていない。  
以下の操作を行い、N種全てのスライムを集めることが最終目標。  
操作:
 - a_i秒かけて保持していないi色のスライムを集める。
 - x秒かけて色iのスライムを色i+1のスライムにする(色Nは色1になる)。

この時、目標を達成するまでの最短時間を求めよ。  

## 制約
 - 2 ≦ N ≦ 2 * 10^3  
 - 1 ≦ a_i ≦ 10^9  
 - 1 ≦ x ≦ 10^9

## 考え方(TLE解)
色iのスライムの集め方を考える。  

 - a_i秒かける
 - a_j秒かけて色jのスライムを集め、  
   {(i - j + N) % N} * x秒かけて色iにする  

この2種類の集め方の最小値を求めれば良い。  
すなわち、  
`min{a_i, a_j + {(i - j + N) % N} * x}`  
を求めれば良い。  

これを実装するとTLEします......(しました)。  

これを解決する手立てを考える。

## 考え方(TLEを避ける解)
先ほどの  
`min{a_i, a_j + {(i - j + N) % N} * x}`  
についてjを固定してみると、  
`min{a_i, a_j + {(i - j + N) % N} * x}`  
をO(N)で求められる。  

jはa_iからを0から増やしていくことは、  
順にa_iから逆方向に減らしていくことと同義であるから、  
O(N^2)で全ての `min{a_i, a_j + {(i - j + N) % N} * x}` を求められる。   

以下、ソースコード。  

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

const ll LINF = 1e18 + 1;
const int MOD = 1e9 + 7;
const int MAX_N = 1e5 + 1;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, x);
  vector< ll > a(N);
  REP(i, N) {
    cin >> a[i];
  }

  ll ans = LINF;
  vector< ll > b(a);
  REP(i, N) {
    ll tmp = x * (ll)i;
    
    REP(j, N) {
      b[j] = min(b[j], a[((ll)(j - i) + N) % N]);
    }
    REP(j, N) {
      tmp += b[j];
    }

    ans = min(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}


```
