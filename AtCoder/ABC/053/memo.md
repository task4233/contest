# ABC053-D : Card Eater

## 問題
[https://beta.atcoder.jp/contests/arc068/tasks/arc068_b]  

[tex:N枚からなるカードの山があり、上からi番目のカードにはA_iと書かれている]  
このカードの山に対して0回以上、以下の操作を行い、残ったカードに書かれた値が互いに異なるようにしたい。  
最後に残るカード数の最大値を求めよ。  

```
操作:  
カードの山から3枚を任意に抜き出す。  
この3枚のカードのうち、  
カードに書かれた値が最小のカードと  
カードに書かれた値が最大のカード2枚を食べる。  
最後の余った1枚をカードの山に戻す。
```

## 制約
 - 3 ≦ N ≦ 10^5
 - Nは奇数
 - 1 ≦ [tex:A_i] ≦ 10^5
 - [tex:A_i]は整数

## 考え方
まず、`操作`がどのような意味を持つのかを考える。  

`操作`とは、
> 操作：カードの山から任意の3枚のカードを抜き出す。  
> 抜き出したカードのうち書かれた値が
> 最大であるようなカード1枚と
> 最小であるようなカード1枚の合計2枚を選んで食べる。  
> その後残った1枚をカードの山に戻す。
とある。  

この`操作`を言い換えると、
 - 3枚が同じカードである時、<u>そのカードが1枚残る</u>。(min = maxなので)  
 - 2枚が同じカードで1枚が別のカードである時、<u>2枚だった方のカードが1枚残る</u>。  
となる。  

ここで、これらの操作は違うように見えるがこれらの操作を言い換えると、  
<u>重複したカードを含めて操作を行うと、重複したカードが1枚残る</u>  
となる。  
さらに簡単にすると、  
<u>重複したカードを含めてN枚入れた時、重複したカードがN%2枚残る</u>
となる。

また、これ以外の場合の操作は行う必要がない。  
なぜなら、これ以外の場合は  
`3枚全てが異なるカードである時`  
であり、この時に操作を行うと最後に残るカードが減ってしまう。  
この問題で問われているのは<u>最大値</u>であるため、この操作は必要ない。  

したがって、この問題で注目するべきなのは、<u>2枚以上重複しているカードのみ</u>である。  
そのようなカードは、以下のように<u>連想配列std::map</u>を用いると容易に見つけられる。  

```cpp
vector< int > A(N);
map< int, int > mp;
REP(i, N) {
  cin >> A[i];
  mp[A[i]]++;
}

int tmp = 0;
EACH(mi, mp) {
  // mi.secondはmiの要素数であり、
  // その要素数-1をすることで2枚以上重複しているカードの差分を求められる。
  tmp += max(0, mi.second - 1);
}

// 重複したカードを含めてN枚入れた時、重複したカードがN%2枚残る。
tmp %= 2;
```

そして、今求めた値は<u>重複したカードの余り</u>であることから、  
最初の全要素数から引くことで最後に余るカード数が求められる。  
すなわち、以下のように答えが導き出せる。  

```cpp
int ans = mp.size() - tmp;
cout << ans << endl;
```

最後に、以上のコードをまとめると以下のようになる。  


```cpp
#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define REP(i,n) FOR(i,0,n)
typedef long long ll;

void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail) {
  cin >> head; CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  CIN(N);
  vector< int > A(N);
  map< int, int > mp;
  REP(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }

  int tmp = 0;
  EACH(mi, mp) {
    tmp += max(0, mi.second - 1);
  }

  tmp %= 2;

  int ans = mp.size() - tmp;
  cout << ans << endl;
  
  return 0;
}

```
