import random

for _ in range(8):
    len = random.randint(1, 10**4)
    result = random.choices(range(-(10**4), 10**4 + 1), k=len)
    result.sort()
    print(result)
