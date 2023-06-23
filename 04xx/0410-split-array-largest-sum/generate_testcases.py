import random

for _ in range(8):
    length = random.randint(1, 1000)
    k = random.randint(1, min(50, length))
    nums = random.choices(range(0, 10**6 + 1), k = length)
    print(nums)
    print(k)
