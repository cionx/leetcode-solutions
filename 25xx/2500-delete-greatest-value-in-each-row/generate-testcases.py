import random

for _ in range(8):
    m = random.randint(1,50)
    n = random.randint(1,50)
    result = []
    for _ in range(m):
        result.append(random.choices(range(1, 101), k = n))
    print(result)
