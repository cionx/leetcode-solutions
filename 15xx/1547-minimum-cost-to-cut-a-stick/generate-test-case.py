import random

n = random.randint(2, 10**6)
cutsSize = min(n - 1, 100)
cuts = random.choices(range(1, n), k = cutsSize)

print(cuts)
print(n)
print(cutsSize)
