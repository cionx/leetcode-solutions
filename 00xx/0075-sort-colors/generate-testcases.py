import random

for _ in range(8):
    length = random.randint(1, 300)
    nums = random.choices([0, 1, 2], k=length)
    print(nums)
