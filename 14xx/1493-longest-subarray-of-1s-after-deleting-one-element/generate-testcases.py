import random

for _ in range(8):
    length = random.randint(1, 10 ** 5)
    nums = random.choices([0, 1], k = length)
    print(nums)
