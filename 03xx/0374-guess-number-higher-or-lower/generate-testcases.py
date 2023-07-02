import random

for _ in range(8):
    n = random.randint(1, 2**31 - 1)
    pick = random.randint(1, n)
    print(n)
    print(pick)
