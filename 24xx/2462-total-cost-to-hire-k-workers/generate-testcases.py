import random

for _ in range(8):
    length = random.randint(1, 10**5)
    costs = random.choices(range(1, 10**5 + 1), k = length)
    k = random.randint(1, length)
    candidates = random.randint(1, length)
    print(costs)
    print(k)
    print(candidates)
