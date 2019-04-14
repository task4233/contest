a = (int)(input())
b = (int)(input())
c = (int)(input())

if a == b and b == c:
    print(-1)
    exit(0)

mn = min(a,min(b,c))

a -= mn
b -= mn
c -= mn

ans = 1010101010101010101010
tmp = 0
while a>0 and a%2==0:
    a /= 2
    ++tmp

ans = min(ans,tmp)

tmp = 0
while b>0 and b%2==0:
    b /= 2
    ++tmp

ans = min(ans,tmp)

tmp = 0
while c>0 and c%2==0:
    c /= 2
    ++tmp

ans = min(ans,tmp)

print(ans)
exit(0)
