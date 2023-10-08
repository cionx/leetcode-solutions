import random

for _ in range(8):
    n = random.randint(3, 100)
    result = []
    for _ in range(n):
        row = random.choices(range(1, 101), k=n)
        result.append(row)
    print(result)
