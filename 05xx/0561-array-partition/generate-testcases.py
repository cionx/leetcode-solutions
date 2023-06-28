import random

for _ in range(8):
    n = random.randint(1, 10**4)
    nums = random.choices(range(-(10**4), 10**4 + 1), k=2 * n)
    print(nums)
