W = int(input())
data = []
while True:
    s = input()
    if s != 'end':
        data.append(list(map(int, s.split(']')[0].split('[')[1].split(', '))))
    else:
        break
# print(data)
n = int(len(data))
dp = [[0 for j in range(10010)] for i in range(1000)]
for i in range(n):
    dp[0][i] = 0

for i in range(n):
    for w in range(W+1):
        if w >= data[i][0]:
            dp[i+1][w] = max(dp[i][w], dp[i][w-data[i][0]]+data[i][1])
        else:
            dp[i+1][w] = dp[i][w]

print(dp[n][W])
