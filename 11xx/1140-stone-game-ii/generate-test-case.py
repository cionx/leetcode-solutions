import random

length = random.randint(1, 100);
piles = random.choices(range(1, 10**4 + 1), k = length)

print(piles)
print(length)
