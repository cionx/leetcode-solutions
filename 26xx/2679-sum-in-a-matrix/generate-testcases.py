import random

for _ in range(8):
    m = random.randint(1, 300)
    n = random.randint(1, 500)
    result = []
    for _ in range(m):
        result.append(random.choices(range(0, 1001), k=n))
    print(result)
