import math

def f(N):
    return int(10 * ( (N + 1) * (N + 2) + ((N + 1 + 1) // 2)**2))

X = int(input().rstrip())

l = 0
r = X

while l < r:
    mid = (l + r) // 2

    if f(mid) < X:
        l = mid + 1
    else:
        r = mid

tetris = 3 if l % 2 == 0 else 2
puntos = f(l)

removed = False
while puntos - (l + 1)* 10 >= X and tetris >= 0:
    puntos -= (l + 1) * 10
    tetris -= 1
    removed = True

if removed == False:
    l += 1

print(l, puntos)