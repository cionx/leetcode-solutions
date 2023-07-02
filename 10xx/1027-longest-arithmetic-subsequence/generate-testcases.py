import random

for _ in range(8):
    length = random.randint(2, 1000)
    nums = random.choices(range(0, 501), k = length)
    print(nums)
