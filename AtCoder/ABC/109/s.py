# coding : utf-8
while (True):
    t = input()
    if (t == EOF):
        break;
    list = input().split(' ')
    ans = 0
    tmp = 0
    for l in list:
        if l == '+':
            ans += tmp
        elif l == '-':
            ans -= tmp
        elif l == '*':
            ans *= tmp
        elif l == '/':
            ans /= tmp
        else:
            tmp = int(l)
    print(ans)
