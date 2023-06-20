import random

for _ in range(16):
    length = random.randint(1, 1000)
    nums = random.choices(range(0, 1001), k=length)
    print(nums)
