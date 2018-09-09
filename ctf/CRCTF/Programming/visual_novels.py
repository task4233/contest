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
