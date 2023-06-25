import random

for _ in range(8):
    length = random.randint(1, 2500)
    nums = random.choices(range(-(10**4), 10**4 + 1), k=length)
    print(nums)
