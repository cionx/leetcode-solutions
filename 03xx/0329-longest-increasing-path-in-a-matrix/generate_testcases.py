import random

MAX = 2**31 - 1

for _ in range(8):
    m = random.randint(1, 200)
    n = random.randint(1, 200)

    result = []
    for _ in range(m):
        result.append(random.choices(range(1, MAX + 1), k=n))

    print(result)
