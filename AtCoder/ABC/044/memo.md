# ABC044/060-D : 桁和/Digit Sum
## 問題文
https://beta.atcoder.jp/contests/abc044/tasks/arc060_b  

2以上の整数bおよび1以上の整数nに対し、関数f(b, n)を次のように定義する。  

 - n < bのときf(b, n) = n
 - n ≧ bのときf(b, n) = f(b, floor(n / b)) + (n % b)
 
整数nとsが与えられたときに、  
f(b, n) = sを満たすような2以上の整数bが存在するか判定せよ。  
そのようなbが複数存在する場合、その最小値を求めよ。  
 
## 制約

 - 1 ≦ n ≦ 10^11
 - 1 ≦ s ≦ 10^11
 - n, sはいずれも整数

## 考察
愚直にbを全探索してみると、以下のようになる。  
```cpp
FOR(bi, 2, n + 1) {
  if (f(bi, n) == S) {
    cout << bi << endl;
  }
}
```

しかし、今回の制約よりn = 1O^11であり、O(n)では間に合わない。  

## 考察(高速化-1: 境界の決定)
そこで、境界Kについて、bを小さいとき(b ≦ K)と大きいとき(K < b)に分けて考える。  
探索を間に合わせるためには、O(√n)もしくはO(log(n))程度なら間に合いそうだ。  

1. O(√n)の時を考える  
   両辺を2乗すると、bが大きいときに(n < b^2)となる。  
   このとき、nをb進数表記したときに必ず2桁以下になる。  
   (なぜなら、b進数表記したときに、下の桁から1, b, b^2(> n), ...と増えていくため)  
   
   ここで、境界を√nとすると、  
   b進数表記したときに2桁以下になり都合がよいので、  
   こちらの境界を採用する。  

## 考察(高速化-2 : bの判定)
先ほどの考察より、n(√n < b)はb進数表記したときに2桁以下になるため、以下のことが言える。  
(ただし、b進数の下1桁目をqとして、下2桁目をpとした。)

 - n = p * b + q  
 - s = p + q  

この2式を解くと、  

 - n - s = p(b - 1) 

という式が得られる。  
この式より、`p` , `b - 1` は `n - s`の約数であることが分かる。  

ここで、 `√n < b` という条件があるため、  
<u>b - 1は√nよりも大きい</u>ことが分かる。  

b - 1が√nよりも大きいことから、  
n - sの約数として対になる `p` は√nよりも小さくなる。  

したがって、この `p` をO(√n)で全探索できる。  

## まとめ(コーディング)
以上をまとめると全体はO(√n)で解くことができた。  

実際のソースコードは以下の通りである(提出コード)。  

```cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl;
#define OK(ok) cout << (ok ? "Yes" : "No") << endl;

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

ll f(ll b, ll n) {
  if (n < b) {
    return n;
  } else {
    return f(b, floor(n / b)) + n % b;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  LCIN(N, S);

  if (N == S) {
    cout << N + 1 << endl;
    return 0;
  }

  // b ≦ √n(bが小さい時)
  FOR(bi, 2, sqrt(N) + 1ll) {
    if (f(bi, N) == S) {
      cout << bi << endl;
      return 0;
    }
  }

  ll ans = LINF;
  // b > √n(bが大きい時)
  FOR(pi, 1, sqrt(N - S) + 1ll) {

    // piが約数でない時は適していない
    if (abs(N - S) % pi != 0) {
      continue;
    }

    // n - s = p(b - 1)より、
    // b = (n - s) / pi + 1として表せる
    ll b = (N - S) / pi + 1;

    // 条件(b > √n)を満たしていない時は適していない
    if (b <= sqrt(N)) {
      continue;
    }
    // 解は最小値である
    if (f(b, N) == S) {
      ans = min(ans, b);
    }
  }

  
  if (ans < LINF) {
    cout << ans << endl;
  } else {
    // 最小値が更新されていない時は解なし
    cout << -1 << endl;
  }
  
  return 0;
}


```
