import random

for _ in range(8):
    m = random.randint(1, 1000);
    n = min(10_000 // m, 1000);

    result: list[list[int]] = []
    for _ in range(m):
        result.append(random.choices(range(1, 10_001), k = n))

    print(result)
