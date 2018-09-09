n, k = map(int, input().split())
a = list(map(int, input().split()))

a = sorted(a)[::-1]
ans = n
sm = 0

for i in range(n):
    if sm + a[i] < k:
        sm += a[i]
    else:
        ans = min(ans, n - i - 1)

print(ans)
