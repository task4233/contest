# Calculation
提示されたコマンドを叩くと四則演算の問題が出て来る。

それを単純に解いて答えていけばFLAGを得られる。

# Prime Factor
提示されたコマンドを叩くと問題が与えられる。

問題の内容は数字を素因数分解して最大の素因数を返すというもの。

エラストテネスの篩を用いて素因数分解分解してmaxを返す関数を作れば良い。

単純に解いていけばFLAGを得られる。

# Visual Novels
提示されたコマンドを叩くと問題が与えられる。

問題の内容自体は単純なナップサックDP。

ただ、愚直に手打ちをしていると間に合わない。

みおずねさんのブログが参考になった。
https://miozune.hatenablog.com/entry/2018/09/09/180415

また、ncコマンドの参考になるページがあったので、それも貼っておく。
https://nkhrlab.hatenablog.com/entry/2017/10/19/205829

```python
W = int(input())
n = int(input())
data = []
for i in range(n):
    s = input()
    data.append(list(map(int, s.split(']')[0].split('[')[1].split(', '))))

dp = [[0 for j in range(10010)] for i in range(1000)]
for i in range(n):
    dp[0][i] = 0

for i in range(n):
    for j in range(W + 1):
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        if j + data[i][0] <= W:
            dp[i + 1][j + data[i][0]] = max(dp[i + 1][j + data[i][0]],
                                            dp[i][j] + data[i][1])

print(dp[n][W])

```
