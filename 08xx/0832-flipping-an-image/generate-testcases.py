import random

for _ in range(8):
    n = random.randint(1, 20)
    result = []
    for _ in range(n):
        row = random.choices([0, 1], k=n)
        result.append(row)
    print(result)
