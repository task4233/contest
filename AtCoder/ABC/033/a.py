N = input()
tmp = N[0]
ok = True
for i in range(len(N)):
    if tmp != N[i]:
        ok = False

if ok:
    print("SAME")
else:
    print("DIFFERENT")
