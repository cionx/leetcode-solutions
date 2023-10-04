import random

for _ in range(8):
    length = random.randint(1, 2000)
    nums = random.choices(range(1, 2001), k=length)
    print(nums)
